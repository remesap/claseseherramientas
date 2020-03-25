//imprimir los valores de la funci�n  de Legendre orden 2, entre 0 y 10, en pasos de 0.1
#include <iostream>
#include <cmath>

int main(void)
{
  const double XMIN = 0, XMAX = 10;
  const double DX = 0.1;
  const int N = 5;
  std::cout.precision(15); std::cout.setf(std::ios::scientific);
  
  for (double x = XMIN; x <= XMAX; x += DX)
    {
      std::cout << x << "\t" << std::legendre(N,x) << "\n";
    }

  return 0;
}
