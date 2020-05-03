#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void slow(float ***data, int size);
void fast(float ***data, int size);

int main(){
  const int n = 512;
  clock_t cputime1, cputime2;
  float ***a;
  int i,j,k;

  // Allocating memory for array/matrix
  a = malloc(n*sizeof(float **));
  for (i=0; i<n; i++){
    a[i] = malloc(n*sizeof(float*));
    for (j=0; j<n; j++)
      a[i][j] = malloc(n*sizeof(float));
  }
  cputime1 = clock();
  slow(a, n);
  cputime2=clock() - cputime1;
  printf("Time with fast index inside: %lf\n", ((double)cputime2)/CLOCKS_PER_SEC);

  cputime1 = clock();
  fast(a, n);
  cputime2=clock() - cputime1;
  printf("Time with fast index outside: %lf\n", ((double)cputime2)/CLOCKS_PER_SEC);

  // Clearing memory
  for (i=0; i<n; i++){
    for (j=0; j<n; j++)
      free(a[i][j]);
    free(a[i]);
  }
  free(a);

  return 0;
}

void slow(float ***data, int size)
{
  int i, j, k;
  for (k=0; k<size; ++k)
    for (j=0; j<size; ++j)
      for (i=0; i<size; ++i)
        data[i][j][k] = 1.0; 
}

void fast(float ***data, int size)
{
  int i, j, k;
  for (i=0; i<size; ++i)
    for (j=0; j<size; ++j)
      for (k=0; k<size; ++k)
        data[i][j][k] = 1.0; 
  
}
