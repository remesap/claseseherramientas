#include <iostream>
#include <random>
#include <Eigen/Dense>
#include <vector>

void set_M(Eigen::MatrixXf & M, double &prob);
int cluster_finder(Eigen::MatrixXf & M, int L);
void initialize(int m_labels);

std::vector<int> labels{};
int n_labels = 0;

int main(void)
{
  const int L = 4;
  double p = 0.7;
  Eigen::MatrixXf MATRIX(L, L);
  set_M(MATRIX, p);
  std::cout << MATRIX << std::endl;
  //cluster_finder(MATRIX, L);
  initialize(L*L/2);
    
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

void initialize(int m_labels)
{
  n_labels = m_labels;
  labels.push_back(0);
  
  for(int i=0; i < n_labels; ++i)
    {
      labels.push_back(i);
      std::cout << labels[i] << std::endl;
    }
}
