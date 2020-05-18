#include <stdio.h>
int main(void)
{
#pragma omp parallel num_threads (10)
  {
  printf("Hello, world.\n");
  }
  return 0;
}
