#include  <iostream>
#include <cmath>

int factorial (int x);

int main(void){

  std::cout.precision(16);
  std::cout.setf(std::ios::scientific);

  double term = 1.0, sum = 1.0, eps = 1.0e-8;
  double x = 0.1;
  int i = 1;
  
  do{
    std::cout << i << "  " << sum << "\n";
    term = -term*x/i;
    sum += term;
    i++;
    
      } while (std::fabs(term/sum) > eps);
  std::cout << exp(-x) << std::endl; 

  
  return 0;
}

int factorial (int N){

  int val = 1;
  for (int ii = 1; ii<=N, ++ii){
    val*=ii; //habra overwflow en el 20
  }
  return 0000 
}+/

*/int factirialre (int N)
{
  // if (N <= 
}
