 #include <iostream>
#include <Eigen/Dense>
 
 
int main()
{
  Eigen::MatrixXd m(8,8);
  for (int i = 0; i < 8; i++)
    for (int j=0; j < 8; j++)
      m(i,j) = 1;
 
  std::cout << m << std::endl;
}
