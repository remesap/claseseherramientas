#include <iostream>
#include "mpi.h"

/* Problem parameters */
double f(double x) {
  return x*x;
}

//const int numberRects = 500000000;
const double lowerLimit = 2.0;
const double upperLimit = 5.0;

int main(int argc, char **argv) 
{
  std::cout.precision(8);
  std::cout.setf(std::ios::fixed);
  int i; 
  double area, at, heigth, width;
  
  int pid, np;
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &pid);
  MPI_Comm_size(MPI_COMM_WORLD, &np);
  
  int numberRects = 0;

  if(0 == pid)
    {
      std::cout << "Por favor escriba el número de rectangulos:\n";
      std::cin >> numberRects;
      std::cout << numberRects << "\n";
    }
  MPI_Bcast(&numberRects, 1, MPI_INT, 0, MPI_COMM_WORLD);
  

  int nrect = numberRects/np;
  int imin = pid*nrect;
  
  // PID |0 |0 |0 |1 |1 |1 |2 |2 |2 |
  // GID |0 |1 |2 |3 |4 |5 |6 |7 |8 |

  double tstart = MPI_Wtime();
  area = 0.0;
  width = (upperLimit - lowerLimit) / numberRects;

  for (i = imin; i < imin + nrect; ++i) {
    at = lowerLimit + i*width + width/2.0;
    heigth = f(at);
    area = area + width*heigth;
  }
  double tend = MPI_Wtime();
  std::cout <<"Time from " << pid << "  " << tend-tstart << std::endl;
  
  //std::printf("The area (pid %d) from %lf to %lf is : %le\n", pid, lowerLimit + imin*width, lowerLimit + (imin+nrect)*width, area);

  double total = 0;
  MPI_Reduce(&area, &total, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
  
  if (0 == pid) {
    std::cout << "El area total es " << total << std::endl;
  }
  
  
  MPI_Finalize();
  
  return 0;
}
