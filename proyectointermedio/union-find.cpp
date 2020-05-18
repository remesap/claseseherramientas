#include <iostream>
#include <random>
#include <Eigen/Dense>
#include <vector>

//functions:

void set_M(Eigen::MatrixXf & M, double &prob); //fill the matrix




int main (void)
{
  const int L = 4;
  double p = 0.7;
  Eigen::MatrixXf MATRIX(L,L);
  std::vector <int> labels;
  Eigen::VectorXi Vector();
  
  for (int i = 0; i < 12; ++i)
    {
    int ii =0
      ii += 1;
    Vector(ii) = 1;
    }
  std::cout << Vector << std::endl;
  
  //std::cout << labels << std::endl;  
  set_M(MATRIX, p);
  std::cout << MATRIX << std::endl;
  
    
  return 0;
}

void set_M(Eigen::MatrixXf & M, double &prob)
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
