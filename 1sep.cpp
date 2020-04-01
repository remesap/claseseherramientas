#include "1.h"

int main(void)
{
  std::cout.precision(16);
  std::cout.setf(std::ios::scientific);
  const double  XMIN = -10*PI, XMAX = 10*PI;
  const double DX = 0.01;

  for (double x = XMIN; x <= XMAX; x += DX)
    {
      std::cout << x << "\t" << sin_pade(x) << "\t" << std::sin(x) << "\n";
    }
  
  return 0;
}


