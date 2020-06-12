#include <iostream>
#include <cmath>
#include <vector>

const double DELTA = 0.01;
const double L = 2.0;
const double N = int(L/DELTA) + 1;
const int STEPS = 450;
const double r = 0.5;
  
typedef std::vector<double> Matrix;

void initial_conditions(Matrix & m);
void boundary_conditions(Matrix & m);
void evolve(Matrix & m);
void print(const Matrix & m);

/*para agregar el círculo miramos qué valores x, y cumplan con que (x^2 + y^2) se aproxime a r^2
  -para lo anterior usamos la condición de que |(x^2 + y^2) - r^2| < 0.001 (un valor cercano a 0)
  -luego buscamos los M(i,j) correspondientes a  estos puntos (x, y) sabiendo que x = i*DELTA y y = j*DELTA
   y hacemos M(i,j) = 0 (voltaje requerido en la frontera que determina el anillo)
*/
int main(void)
{
  std::cout.precision(6);
  std::cout.setf(std::ios::fixed);
  
  Matrix data(N*N);
  
  initial_conditions(data);
  boundary_conditions(data);

  for (int step = 0; step < STEPS; ++step)
    evolve(data);

  print(data);

  return 0;
}

void initial_conditions(Matrix & m)
{
  for (int ii = 0; ii < N; ++ii)
    for (int jj = 0; jj < N; ++jj)
      {
	m[N*ii + jj] = 5.0;
      }
}

void boundary_conditions(Matrix & m)
{
  int ii = 0, jj= 0;

  ii = 0; //borde superior
  for (jj = 0; jj < N; ++jj)
    m[N*ii + jj] = 10.0;

  ii = N-1; //borde inferior
  for (jj = 0; jj < N; ++jj)
    m[N*ii + jj] = -10.0;

  jj = 0; //borde izquierdo
  for (ii = 0; ii < N; ++ii)
    m[N*ii + jj] = 0;

  jj = N-1; //borde derecho
  for (ii = 0; ii < N; ++ii)
    m[N*ii + jj] = 0;

  //círculo:
  
  for (int ii = 0; ii < N; ++ii)
    for (int jj = 0; jj < N; ++jj)
      {
	double x = ii*DELTA, y = jj*DELTA;
	if ( std::fabs(r*r - ((x-1)*(x-1) + (y-1)*(y-1))) < 1.0e-2 )
	  m[N*ii + jj] = 0.0;
      }
  

}

void evolve(Matrix & m)
{
  for (int ii = 0; ii < N; ++ii)
    for (int jj = 0; jj < N; ++jj)
      {
	//comprobar que no se esté en la frontera
	if (ii == 0) continue;
	if (ii == N-1) continue;
	if (jj == 0) continue;
	if (ii == N-1) continue;
	if (m[N*ii + jj] == 0.0) continue; //si está en el círculo 
	//evolve
	m[N*ii + jj] = 1/4.0*(m[N*(ii+1)+jj] + m[N*(ii-1)+jj] + m[N*ii+(jj+1)] + m[N*ii+(jj-1)]);
      }
 
 
}


void print(const Matrix & m)
{
  for (int ii = 0; ii < N; ++ii)
    {
      for (int jj = 0; jj < N; ++jj)
	{
	  double x = ii*DELTA, y = jj*DELTA;
	  std::cout << x << " " << y << " " << m[N*ii + jj] << "\n";
	}
      std::cout << "\n";
    }
}
