#include <iostream>
#include <eigen3/Eigen/Dense> //se puso puso eigen3 en el header
 
int main()
{
  Eigen::MatrixXd A = Eigen::MatrixXd::Random(20,20);
  std::cout << "Here is the matrix A:\n" << A << std::endl;
  Eigen::SelfAdjointEigenSolver<Eigen::MatrixXd> eigensolver(A);
  //if (eigensolver.info() != Success) abort();
  std::cout << "The eigenvalues of A are:\n" << eigensolver.eigenvalues() << std::endl;
  std::cout << "Here's a matrix whose columns are eigenvectors of A \n" << std::endl;
}

