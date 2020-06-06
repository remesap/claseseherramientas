#include <iostream>
#include <cmath>
#include "mpi.h"

int main(int argc, char **argv)
{
  std::cout.precision(8);
  std::cout.setf(std::ios::fixed);
  int ii;
  double vii, suma;
  
  
  int pid, np;
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &pid);
  MPI_Comm_size(MPI_COMM_WORLD, &np);

  int N = 0;
  double p = 0;
  if (0 == pid)
    {
      std::cout << "Por favor escriba el valor de N:\n";
      std::cin >> N;
      std::cout << "Por favor escriba el valor de p:\n";
      std::cin >> p;
    }
  MPI_Bcast(&N, 1, MPI_INT, 0, MPI_COMM_WORLD);
  MPI_Bcast(&p, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
  
  int sectionsize = N/np; //tamano de cada pedazo de vector
  int imin = pid*sectionsize;

  double tstart = MPI_Wtime();
  /*
  if ( pid == np-1)
    for (ii = imin; ii < N; ++ii)
    {
      vii = 2*ii;
      suma += std::pow(vii, p);
      }*/

  suma = 0.0;
    
  for (ii = imin; ii < imin + sectionsize; ++ii)
    {
      vii = 2*ii;
      suma = suma + std::pow(vii, p);
    }
  
  double tend = MPI_Wtime();
  std::cout << "Tiempo de " << pid << "  " << tend - tstart << std::endl;
  double sumatotal = 0;
  MPI_Reduce(&suma, &sumatotal, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

  if (0 == pid)
    {
      std::cout << "suma: " << sumatotal << std::endl;
      double norma = std::pow(sumatotal, 1.0/p);
      std::cout << "norma: " << norma << std::endl;
    }

  
  MPI_Finalize();
  
  return 0;
}

//161700 - (2*49)^2 - (2*48)^2 = 142880

