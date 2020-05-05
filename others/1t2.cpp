#include <cstdio>
#include <cmath>

double myatan( double x, int n );

int main(void)
{
  const int NSTEPS = 53;
  const double X = 4.2;
  const double EXACT = std::atan(X);
  for (int n = 1; n <= NSTEPS; n += 2)
    {
      double my = myatan(X, n);
      double diff = std::fabs( 1 - my/EXACT);
      std::printf( "%25d\t%25.16e\n", n, diff);
    }

  return 0;
  
}

double myatan( double x, int n )
{
  double a = std::pow( 2, -1.0*n/2);
  double b = x/( 1 + std::sqrt(1 + std::pow(x, 2)));
  double c = 1.0, d = 1.0;

  for ( int i = 1; i <= n; i++ )
    {
      
      c = 2*c/(1 + a);
      d = 2*a*b/(1 + std::pow(b, 2));
      d = d/(1 + std::sqrt(1 - std::pow(d, 2)));
      d = (b + d)/(1-b*d);
      b = d/(1 + std::sqrt(1 + std::pow(d, 2)));
      a = 2*std::sqrt(a)/(1 + a);

      if ((1 - a) <= std::pow(2, -1.0*n))
	break;
    }
  

  return c*std::log((1 + b)/(1 - b));
					       
}
