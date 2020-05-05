#include <iostream>
#include <cmath>

const double PI = M_PI;

double sin_pade(double x);
double sin_aux(double u);


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


double sin_pade(double x)
{
  double u = 0;
  double X = std::fabs(x);
  int n = int(X/(PI/2));

  if ( std::fabs(x) > PI/2 && n%2 == 0)
    {
      u = std::pow(-1,n/2)*(x - n/2*PI);
      return sin_pade(u);
    }

  if ( std::fabs(x) > PI/2 && n%2 != 0)
    {
      u = std::pow(-1,(n+1)/2)*(x - (n+1)/2*PI);
      return sin_pade(u);
    }
  
  if ( X >= 0 && X < 1.0e-8 )
    {
    return x;
    }
  
  if ( X >= 1.0e-8 && X <= PI/6)
    {
    u = x;
    return sin_aux(u);
    }
  
  
  if ( X > PI/6 && X <= PI/2 )
    {
      u = x/3;
      return (3 - 4*std::pow(sin_aux(u), 2))*sin_aux(u) ;
    }

  return 0;
}

double sin_aux(double u)
{
  return u*((1-29593/207636*std::pow(u,2) + 34911/7613320*std::pow(u,4) - 479249/11511339840*std::pow(u,6))/(1 + 1671/69212*std::pow(u,2) + 97/351384*std::pow(u,4) + 2623/1644477120*std::pow(u,6)));
}
