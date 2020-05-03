--------------------------------------------------------------------------------
I1 cache:         32768 B, 64 B, 8-way associative
D1 cache:         32768 B, 64 B, 8-way associative
LL cache:         2097152 B, 64 B, 8-way associative
Command:          ./a.out 5000 6000
Data file:        cachegrind.out.16951
Events recorded:  Ir I1mr ILmr Dr D1mr DLmr Dw D1mw DLmw
Events shown:     Ir I1mr ILmr Dr D1mr DLmr Dw D1mw DLmw
Event sort order: Ir I1mr ILmr Dr D1mr DLmr Dw D1mw DLmw
Thresholds:       0.1 100 100 100 100 100 100 100 100
Include dirs:     
User annotated:   
Auto-annotation:  on

--------------------------------------------------------------------------------
Ir            I1mr  ILmr  Dr          D1mr   DLmr  Dw         D1mw       DLmw       
--------------------------------------------------------------------------------
1,442,382,930 1,744 1,674 690,592,727 14,586 8,574 90,200,659 37,502,514 11,257,424  PROGRAM TOTALS

--------------------------------------------------------------------------------
Ir          I1mr ILmr Dr          D1mr  DLmr  Dw         D1mw       DLmw       file:function
--------------------------------------------------------------------------------
510,055,013    3    3 240,025,004     0     0 30,005,005  3,750,000 3,750,000  /home/renzo/herramientas/hc/profilingII/gprof_example.cpp:option1(long*, int, int)
510,055,013    1    1 240,025,004     0     0 30,005,005 30,000,000 3,755,899  /home/renzo/herramientas/hc/profilingII/gprof_example.cpp:option2(long*, int, int)
420,000,013    1    1 210,000,005     0     0 30,000,005  3,750,001 3,749,901  /home/renzo/herramientas/hc/profilingII/gprof_example.cpp:option3(long*, int, int)

--------------------------------------------------------------------------------
-- Auto-annotated source: /home/renzo/herramientas/hc/profilingII/gprof_example.cpp
--------------------------------------------------------------------------------
Ir          I1mr ILmr Dr          D1mr DLmr Dw         D1mw       DLmw      

-- line 9 ----------------------------------------
          .    .    .           .    .    .          .          .         .  
          .    .    .           .    .    .          .          .         .  void option1(long *arr, int ix, int iy);
          .    .    .           .    .    .          .          .         .  void option2(long *arr, int ix, int iy);
          .    .    .           .    .    .          .          .         .  void option3(long *arr, int ix, int iy);
          .    .    .           .    .    .          .          .         .  
          .    .    .           .    .    .          .          .         .  void print_elapsed(auto start, auto end );
          .    .    .           .    .    .          .          .         .  
          .    .    .           .    .    .          .          .         .  int main(int argc, char **argv)
          5    1    1           0    0    0          3          0         0  {
          2    0    0           1    0    0          0          0         0    if (argc < 3){
          .    .    .           .    .    .          .          .         .      printf("Usage: cacheTest sizeI sizeJ\nIn first input.\n");
          .    .    .           .    .    .          .          .         .      return 1;
          .    .    .           .    .    .          .          .         .    }
          7    0    0           2    1    0          2          0         0    long sI = atoi(argv[1]);
          7    1    1           2    0    0          2          0         0    long sJ = atoi(argv[2]);
          .    .    .           .    .    .          .          .         .  
          2    0    0           0    0    0          2          0         0    auto start = std::chrono::steady_clock::now();
          .    .    .           .    .    .          .          .         .    
          6    0    0           2    0    0          1          0         0    printf("Operating on matrix of size %ld by %ld\n", sI, sJ);
          .    .    .           .    .    .          .          .         .  
          9    1    1           2    0    0          2          0         0    long *arr = new long[sI*sJ]; // double array.
          2    0    0           0    0    0          2          0         0    auto end = std::chrono::steady_clock::now();
          5    0    0           2    0    0          1          0         0    print_elapsed(start, end);
          .    .    .           .    .    .          .          .         .    
          .    .    .           .    .    .          .          .         .    // option 1
          2    1    1           0    0    0          2          0         0    start = std::chrono::steady_clock::now();
          8    0    0           3    0    0          1          0         0    option1(arr, sI, sJ);
          2    0    0           0    0    0          2          1         1    end = std::chrono::steady_clock::now();
          5    0    0           2    0    0          1          0         0    print_elapsed(start, end);
          .    .    .           .    .    .          .          .         .    
          .    .    .           .    .    .          .          .         .    // option 2
          2    0    0           0    0    0          2          0         0    start = std::chrono::steady_clock::now();
          8    1    1           3    0    0          1          0         0    option2(arr, sI, sJ);
          2    0    0           0    0    0          2          1         1    end = std::chrono::steady_clock::now();
          5    0    0           2    0    0          1          0         0    print_elapsed(start, end);
          .    .    .           .    .    .          .          .         .  
          .    .    .           .    .    .          .          .         .    // option 3
          2    0    0           0    0    0          2          0         0    start = std::chrono::steady_clock::now();
          8    1    1           3    0    0          1          0         0    option3(arr, sI, sJ);
          2    0    0           0    0    0          2          1         1    end = std::chrono::steady_clock::now();
          5    0    0           2    0    0          1          0         0    print_elapsed(start, end);
          .    .    .           .    .    .          .          .         .  
          6    0    0           2    1    1          1          0         0    printf("%ld\n", arr[0]);
          .    .    .           .    .    .          .          .         .    
          2    0    0           0    0    0          0          0         0    return 0;
          2    0    0           2    1    1          0          0         0  }
          .    .    .           .    .    .          .          .         .    
          .    .    .           .    .    .          .          .         .  
         24    1    1           0    0    0         16          0         0  void print_elapsed(auto start, auto end )
          .    .    .           .    .    .          .          .         .  {
         16    0    0           0    0    0          4          0         0    std::cout << "Elapsed time in ms: "
         64    0    0           0    0    0         24          0         0              << std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count()
         12    0    0           0    0    0          4          0         0              << "\n";
         20    0    0          12    0    0          0          0         0  }
          .    .    .           .    .    .          .          .         .  
          .    .    .           .    .    .          .          .         .  
          .    .    .           .    .    .          .          .         .  void option1(long *arr, int ix, int iy)
          5    1    1           0    0    0          4          0         0  {
     30,005    0    0      15,002    0    0          1          0         0    for (long i=0; i < ix; ++i)
180,025,000    2    2  90,010,000    0    0      5,000          0         0      for (long j=0; j < iy; ++j)
330,000,000    0    0 150,000,000    0    0 30,000,000  3,750,000 3,750,000        arr[(i * (iy)) + j ] = i;
          .    .    .           .    .    .          .          .         .    
          3    0    0           2    0    0          0          0         0  }
          .    .    .           .    .    .          .          .         .  
          .    .    .           .    .    .          .          .         .  
          .    .    .           .    .    .          .          .         .  void option2(long *arr, int ix, int iy)
          5    0    0           0    0    0          4          0         0  {
     30,005    0    0      15,002    0    0          1          0         0      for (long i=0; i < ix; ++i)
180,025,000    0    0  90,010,000    0    0      5,000          0         0        for (long j=0; j < iy; ++j)
330,000,000    1    1 150,000,000    0    0 30,000,000 30,000,000 3,755,899           arr[(j * (ix)) + i ] = i;
          3    0    0           2    0    0          0          0         0  }
          .    .    .           .    .    .          .          .         .  
          .    .    .           .    .    .          .          .         .  void option3(long *arr, int ix, int iy)
          5    1    1           0    0    0          4          0         0  {
420,000,005    0    0 210,000,003    0    0 30,000,001  3,750,001 3,749,901      for (int i=0; i < ix*iy; ++i) arr[i] = i;
         22    2    2           8    1    0          5          0         0  }
          .    .    .           .    .    .          .          .         .  
          .    .    .           .    .    .          .          .         .  

--------------------------------------------------------------------------------
Ir            I1mr ILmr Dr          D1mr DLmr Dw         D1mw       DLmw       
--------------------------------------------------------------------------------
1,440,110,300   14   14 690,050,061    4    2 90,010,102 37,500,004 11,255,803  events annotated

