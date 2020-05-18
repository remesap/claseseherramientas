#include "mpi.h"
#include <iostream>

int main(int argc, char **argv)
{
  int noProcesses;
  int processId;
  MPI_Init(&argc, &argv); /* Mandatory */
  MPI_Comm_size(MPI_COMM_WORLD, &noProcesses);
  MPI_Comm_rank(MPI_COMM_WORLD, &processId); 

  std::cout << "I am process -> " << processId << " out of -> " << noProcesses << std::endl;

  MPI_Finalize(); /* Mandatory */

  return 0; 
}          
