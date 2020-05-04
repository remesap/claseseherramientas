#include <iostream>
#include <eigen3/Eigen/Dense>

     int main(void)
     {
       srand(1); //modifica la semilla para nuestro generador aleatorio
       Eigen::MatrixXd m = Eigen::MatrixXd::Random(5,5);
       std::cout << m << std::endl;
       
       return 0; 
     }
