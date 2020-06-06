#include <iostream>
#include <cmath>

int main(int argc, char **argv)
{
  std::cout.precision(8);
  std::cout.setf(std::ios::fixed);
  int N;
  double p;

  double vii = 0;

  std::cout << "Por favor escriba el valor de N:\n";
  std::cin >> N;
  std::cout << "Por favor escriba el valor de p:\n";
  std::cin >> p;
  
  std::cout << "\n";

  double suma = 0;
  for (int ii = 0; ii < N; ++ii)
    {
      vii = 2*ii;
      suma += std::pow(vii,p); 
    }
  
  double norma = std::pow(suma, 1.0/p);
  std::cout << "norma: " << norma << std::endl;
  
  return 0;
}
