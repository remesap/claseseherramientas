#include <iostream>
#include <cmath>
#include <vector>
#include "mpi.h"

int main(int argc, char **argv)
{
  std::cout.precision(8);
  std::cout.setf(std::ios::fixed);

  std::cout << "Por favor escriba el valor de N:\n";
  std::cin >> N;
  std::cout << "Por favor escriba el valor de p:\n";
  std::cin >> p;
      
  std::vector<double> myvector(N, 0);
  
  int pid, np;
  MPI_Init(&argc, &argv);  //inicia la paralelización
  MPI_Comm_rank(MPI_COMM_WORLD, &pid);
  MPI_Comm_size(MPI_COMM_WORLD, &np);

  /* AIUUUDAAA!!!!!*/
  int sectionsize = N/np; //tamano de cada pedazo de vector
  int imin = pid*sectionsize;

  double tstart = MPI_Wtime();
  double suma = 0.0;
  for (int ii = imin; ii < imin + sectionsize; ++ii)
    {
      myvector[ii] = 2*ii;
      suma += std::pow(myvector[ii], p);
      std::cout << myvector[ii] << "  ";
    }
  double tend = MPI_Wtime();
  std::cout << "Tiempo de " << pid << "  " << tend - tstart << std::endl;
  double sumatotal = 0;
  MPI_Reduce(&suma, &sumatotal, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

  if (0 == pid)
    {
      for (int ii = 0; ii < N; ++ii)
	std::cout << myvector[ii] << "  ";
      std::cout << "\n";
      double norma = std::pow(suma, 1.0/p);
      std::cout << "norma: " << norma << std::endl;
    }

  
  MPI_Finalize();
  
  return 0;
}
