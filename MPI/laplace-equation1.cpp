#include <iostream>
#include <cmath>
#include <vector>

const double DELTA = 0.1;
const double L = 1.566;
const double N = int(L/DELTA) + 1;

typedef std::vector<double> Matrix;

void initial_conditions(Matrix & m);
void boundary_conditions(Matrix & m);
void print(const Matrix & m);

int main(void)
{
  Matrix data(N*N);
  
  initial_conditions(data);
  boundary_conditions(data);

  //evolve(data);

  print(data);

  return 0;
}

void initial_conditions(Matrix & m)
{
  for (int ii = 0; ii < N; ++ii)
    for (int jj = 0; jj < N; ++jj)
      {
	m[N*ii + jj] = 1.0;
      }
}

void boundary_conditions(Matrix & m)
{
  int ii = 0, jj= 0;

  ii = 0; //borde superior
  for (jj = 0; jj < N; ++jj)
    m[N*ii + jj] = 100;

  ii = N-1; //borde inferior
  for (jj = 0; jj < N; ++jj)
    m[N*ii + jj] = 0;

  jj = 0; //borde izquierdo
  for (ii = 0; ii < N; ++ii)
    m[N*ii + jj] = 0;

  jj = N-1; //borde derecho
  for (ii = 0; ii < N; ++ii)
    m[N*ii + jj] = 0;

}


void print(const Matrix & m)
{
  for (int ii = 0; ii < N; ++ii)
    for (int jj = 0; jj < N; ++jj)
      {
	std::cout << ii*DELTA << " " << jj*DELTA << "  " << m[N*ii + jj] << "\n";
      }
  std::cout << "\n";
}
