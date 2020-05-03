--------------------------------------------------------------------------------
I1 cache:         32768 B, 64 B, 8-way associative
D1 cache:         32768 B, 64 B, 8-way associative
LL cache:         2097152 B, 64 B, 8-way associative
Command:          ./a.out
Data file:        cachegrind.out.17061
Events recorded:  Ir I1mr ILmr Dr D1mr DLmr Dw D1mw DLmw
Events shown:     Ir I1mr ILmr Dr D1mr DLmr Dw D1mw DLmw
Event sort order: Ir I1mr ILmr Dr D1mr DLmr Dw D1mw DLmw
Thresholds:       0.1 100 100 100 100 100 100 100 100
Include dirs:     
User annotated:   
Auto-annotation:  on

--------------------------------------------------------------------------------
Ir             I1mr  ILmr  Dr             D1mr    DLmr    Dw            D1mw       DLmw       
--------------------------------------------------------------------------------
62,267,165,209 1,197 1,189 15,838,896,915 174,197 166,817 1,754,078,795 42,571,318 42,568,745  PROGRAM TOTALS

--------------------------------------------------------------------------------
Ir             I1mr ILmr Dr            D1mr    DLmr    Dw          D1mw       DLmw        file:function
--------------------------------------------------------------------------------
40,453,013,504   19   19 6,425,673,728     100     100           0          0          0  ???:__ieee754_pow_sse2
16,391,642,725   18   18 7,524,862,495 166,462 164,158 941,364,260 42,304,828 42,304,321  /home/renzo/herramientas/hc/profilingII/CodigosIvan/operations.c:main
 4,835,508,224    4    4 1,342,177,280       2       2 805,306,368          0          0  ???:pow@@GLIBC_2.29
   537,133,835   35   35   537,133,728      35      30          26          1          1  ???:???

--------------------------------------------------------------------------------
-- Auto-annotated source: /home/renzo/herramientas/hc/profilingII/CodigosIvan/operations.c
--------------------------------------------------------------------------------
Ir            I1mr ILmr Dr            D1mr   DLmr   Dw          D1mw      DLmw      

-- line 4 ----------------------------------------
            .    .    .             .      .      .           .         .         .   * with -O3 flag.
            .    .    .             .      .      .           .         .         .   */
            .    .    .             .      .      .           .         .         .  
            .    .    .             .      .      .           .         .         .  #include <stdio.h>
            .    .    .             .      .      .           .         .         .  #include <stdlib.h>
            .    .    .             .      .      .           .         .         .  #include <time.h>
            .    .    .             .      .      .           .         .         .  #include <math.h>
            .    .    .             .      .      .           .         .         .  
            4    0    0             0      0      0           2         0         0  int main(){
            1    0    0             0      0      0           1         0         0    const int n = 512;
            .    .    .             .      .      .           .         .         .    float ***a;
            .    .    .             .      .      .           .         .         .    clock_t cputime1, cputime2;
            .    .    .             .      .      .           .         .         .    float tmp;
            .    .    .             .      .      .           .         .         .    int i,j,k;
            .    .    .             .      .      .           .         .         .  
            .    .    .             .      .      .           .         .         .    // Allocating memory for array/matrix
            6    0    0             1      0      0           2         0         0    a = malloc(n*sizeof(float **));
        2,053    1    1         1,538      0      0           1         0         0    for (i=0; i<n; i++){
        5,632    1    1         1,536      0      0       1,024        64        64      a[i] = malloc(n*sizeof(float*));
    1,051,136    0    0       787,456      0      0         512         0         0      for (j=0; j<n; j++)
    4,194,304    0    0     1,310,720      0      0     524,288    32,764    32,258        a[i][j] = malloc(n*sizeof(float));
            .    .    .             .      .      .           .         .         .    }
            .    .    .             .      .      .           .         .         .  
            2    1    1             0      0      0           2         0         0    cputime1 = clock();
        2,053    1    1         1,538      0      0           1         0         0    for (i=0; i<n; i++)
    1,051,136    0    0       787,456      0      0         512         0         0      for (j=0; j<n; j++)
  538,181,632    1    1   403,177,472      0      0     262,144         0         0        for (k=0; k<n; k++)
2,818,572,288    0    0 1,073,741,824 33,088 32,832 268,435,456 8,454,400 8,454,399          a[i][j][k] = pow((float)k,3);
            3    0    0             1      0      0           2         0         0    cputime2 = clock() - cputime1;
            6    1    1             2      0      0           1         0         0    printf("Time to compute integer powers:\t %f\n", ((double)cputime2)/CLOCKS_PER_SEC);
            .    .    .             .      .      .           .         .         .    
            2    0    0             0      0      0           2         0         0    cputime1 = clock();
        2,053    1    1         1,538      0      0           1         0         0    for (i=0; i<n; i++)
    1,051,136    0    0       787,456      0      0         512         0         0      for (j=0; j<n; j++)
  538,181,632    0    0   403,177,472      0      0     262,144         0         0        for (k=0; k<n; k++)
2,818,572,288    1    1 1,073,741,824 33,087 32,831 268,435,456 8,454,400 8,454,400          a[i][j][k] = pow((float)k,3.0);
            3    0    0             1      0      0           2         0         0    cputime2 = clock() - cputime1;
            6    1    1             2      0      0           1         0         0    printf("Time to compute non-integer powers:\t %f\n", ((double)cputime2)/CLOCKS_PER_SEC);
            .    .    .             .      .      .           .         .         .  
            2    0    0             0      0      0           2         0         0    cputime1 = clock();
        2,053    1    1         1,538      0      0           1         0         0    for (i=0; i<n; i++)
    1,051,136    0    0       787,456      0      0         512         0         0      for (j=0; j<n; j++)
  538,181,632    0    0   403,177,472      0      0     262,144         0         0        for (k=0; k<n; k++)
2,818,572,288    1    1 1,073,741,824 33,087 32,831 134,217,728 8,454,400 8,454,400          a[i][j][k] = ((float)k)/((float)(i+1));
            3    0    0             1      0      0           2         0         0    cputime2 = clock() - cputime1;
            6    1    1             2      1      1           1         0         0    printf("Time to compute divisions:\t %f\n", ((double)cputime2)/CLOCKS_PER_SEC);
            .    .    .             .      .      .           .         .         .  
            2    0    0             0      0      0           2         0         0    cputime1 = clock();
        2,053    1    1         1,538      0      0           1         0         0    for (i=0; i<n; i++){
        3,584    1    1         1,024    511      0         512         0         0      tmp = 1.0/(i+1);
    1,051,136    1    1       787,456      0      0         512         0         0      for (j=0; j<n; j++)
  538,181,632    0    0   403,177,472      0      0     262,144         0         0        for (k=0; k<n; k++)
2,415,919,104    0    0 1,073,741,824 33,087 32,831 134,217,728 8,454,400 8,454,400          a[i][j][k] = ((float)k)*tmp;
            .    .    .             .      .      .           .         .         .    }
            3    0    0             1      0      0           2         0         0    cputime2 = clock() - cputime1;
            6    0    0             2      1      0           1         0         0    printf("Time to compute multiplications:\t %f\n", ((double)cputime2)/CLOCKS_PER_SEC);
            .    .    .             .      .      .           .         .         .  
            2    1    1             0      0      0           2         0         0    cputime1 = clock();
        2,053    1    1         1,538      0      0           1         0         0    for (i=0; i<n; i++){
        3,584    0    0         1,024    511      0         512         0         0      tmp = 1.0/(i+1);
    1,051,136    0    0       787,456      0      0         512         0         0      for (j=0; j<n; j++)
  538,181,632    0    0   403,177,472      0      0     262,144         0         0        for (k=0; k<n; k++)
2,818,572,288    1    1 1,207,959,552 33,087 32,831 134,217,728 8,454,400 8,454,400          a[i][j][k] = ((float)k)*tmp+(float)j;
            .    .    .             .      .      .           .         .         .    }
            3    0    0             1      0      0           2         0         0    cputime2 = clock() - cputime1;
            6    0    0             2      1      0           1         0         0    printf("Time to add-multiply floats:\t %f\n", ((double)cputime2)/CLOCKS_PER_SEC);
            1    0    0             0      0      0           0         0         0    return 0;
            4    0    0             3      1      1           0         0         0  }

--------------------------------------------------------------------------------
Ir             I1mr ILmr Dr            D1mr    DLmr    Dw          D1mw       DLmw       
--------------------------------------------------------------------------------
16,391,642,725   18   18 7,524,862,495 166,462 164,158 941,364,260 42,304,828 42,304,321  events annotated

