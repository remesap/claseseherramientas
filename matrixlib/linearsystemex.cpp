#include <iostream>
#include <eigen3/Eigen/Dense>

      int main()
      {
        Eigen::MatrixXf A = Eigen::MatrixXf::Random(40,40);
        Eigen::VectorXf b = Eigen::VectorXf::Random(40);

        //std::cout << "Here is the matrix A:\n" << A << std::endl;
        //std::cout << "Here is the vector b:\n" << b << std::endl;
	Eigen::VectorXf x = A.fullPivHouseholderQr().solve(b);
        //std::cout << "The solution is:\n" << x << std::endl;
        std::cout << "Verification:\n" << (A*x - b).norm() << std::endl;
      }
