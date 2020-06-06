#include <iostream>
#include <cmath>
#include "mpi.h"

int main(int argc, char **argv)
{
  std::cout.precision(8); std::cout.setf(std::ios::fixed);
  int pid, np;
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &pid);
  MPI_Comm_size(MPI_COMM_WORLD, &np);

  int N = 0;
  double p = 0;
  if (0 == pid)
    {
      std::cout << "Por favor escriba el tamano N del vector:\n";
      std::cin >> N;
      std::cout << "Por favor escriba un valor real para p:\n";
      std::cin >> p;
    }
  MPI_Bcast(&N, 1, MPI_INT, 0, MPI_COMM_WORLD);
  MPI_Bcast(&p, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
  
  int sectionsize = N/np; //tamano de cada pedazo de vector
  int imin = pid*sectionsize; //donde inicia el proceso
  double suma = 0.0, vii = 0.0; 
  
  double tstart = MPI_Wtime(); 
  if ( pid == np-1)  //para el último pedazo que en general será de tamano "sectionsize + (N % np)"
    for (int ii = imin; ii < N; ++ii)
      {
	vii = 2*ii;
	suma += std::pow(vii, p);
      }

  else
    for (int ii = imin; ii < imin + sectionsize; ++ii) 
      {
	vii = 2*ii;
	suma = suma + std::pow(vii, p);
      }
  double tend = MPI_Wtime(); 
  std::cout << "Tiempo de " << pid << "  " << tend - tstart << std::endl;
  
  double sumatotal = 0;
  MPI_Reduce(&suma, &sumatotal, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

  if (0 == pid)  //resultados
    {
      //std::cout << "suma: " << sumatotal << std::endl;
      double norma = std::pow(sumatotal, 1.0/p);
      std::cout << "norma p: " << norma << std::endl;
    }

  MPI_Finalize();
  
  return 0;
}
