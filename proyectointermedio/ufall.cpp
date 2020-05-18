#include <iostream>
#include <random>
#include <Eigen/Dense>
#include <vector>

//functions:

void set_M(Eigen::MatrixXi & M, double &prob); //fill the matrix
int uf_find(int x, int labs[] );
int uf_union(int x, int y);



int main (void)
{
  const int L = 10;
  double p = 0.7;
  Eigen::MatrixXi MATRIX(L,L);
  set_M(MATRIX, p);

  int largest_label = 0;
  int left = 0, above = 0;

  int labels [10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; //un arreglo provisional que contiene 10 labels  
  
  for (int i = 1; i < MATRIX.cols(); ++i)
  {
    for (int j = 1; j < MATRIX.cols(); ++j)
      if (MATRIX(i, j) == 1)
	{
	  left = MATRIX(i, j-1);
	  above = MATRIX(i-1,j);
	  
	  if ( left == 0 && above == 0){    //ni la de la izq. ni la de arriba están ocupadas
	    largest_label = largest_label + 1;
	    MATRIX(i, j) = largest_label;
	  }

	  else if ( left == 1 && above == 0) //izq. ocupada pero arriba no
	    uf_find(left, labels);

	  else if ( left == 0 && above == 1) //izq. vacía y arriba ocupada
	    uf_find(above, labels);

	  else{                             //ni izq. ni arriba ocupadas
	    uf_union(left, above); 
	    MATRIX(i, j) = uf_find(left, labels);
	  }
	    
	}
  }

  std::cout << MATRIX << std::endl;
    
  return 0;
}

void set_M(Eigen::MatrixXi & M, double &prob)
{
  int SEED = 1;
  std::mt19937 gen(SEED);
  std::binomial_distribution<int> dis(1, prob);//(objs 0 or 1,success)

  for (int i = 0; i < M.cols(); ++i)
  {
    for (int j = 0; j < M.cols(); ++j)
      M(i, j) = dis(gen);
  }
}

int uf_find(int x, int labs[])  //donde x es un elemento de la matriz
{
  for (int i = 0; i < 10; ++i) {
    if ( x == labs[i])
      return x; 
  }

  return x;
}

    
int uf_union(int x, int y)
{
  if ( x > y)
    x = y;
  if (x < y)
    y = x;

  return x;
}






