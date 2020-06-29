#include <cstdio>
#include <cmath>
#include <random>
#include <cstdlib>
#include "mpi.h"

int main(int argc, char **argv) 
{
  int pid, np;
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &pid);
  MPI_Comm_size(MPI_COMM_WORLD, &np);

  int N = 0;
  if (0 == pid) {
    std::printf("Por favor escriba el total de elementos N:\n");
    std::scanf("%d", &N);
  }
  MPI_Bcast(&N, 1, MPI_INT, 0, MPI_COMM_WORLD);

  //tstart = MPI_Wtime();
  std::mt19937 gen(seed);
  std::uniform_real_distribution<double> d (-1.0, 1.0); 
  int nlocal = N/np;  //nlocal ->number of rows 'x', N -> number of columns 'y'
  int * data = new int [nlocal*N]{0};
  //llenar los sitios correspondientes
  
  //imprimir y enviar
  if (0 != pid)
    {
      MPI_Send(data, nlocal*N, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
  else if (0 == pid)
    {
      print(data, nlocal, N);
      for (int i = 1; i < np; ++ii)
	{
	  MPI_Recv(data, nlocal*N, MPI_INT, ii, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
	  print(data, nlocal, n);
	}
    }
  //double tend = MPI_Wtime();
  std::printf("Time from pid %d: %lf\n", pid, tend-tstart);
  std::printf("Nc   from pid %d: %d\n", pid, Nc);

  int Nc_total = 0;
  MPI_Reduce(&Nc, &Nc_total, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
  
  if (0 == pid) {
    std::printf("pi: %25.16le\n", 4.0*Nc_total/N);
  }
  

  MPI_Finalize();
  
  return 0;
}
