#include <iostream>
#include <eigen3/Eigen/Dense>

     int main(void)
     {
       srand(1); //modifica la semilla para nuestro generador aleatorio
       Eigen::MatrixXd m = Eigen::MatrixXd::Random(80,80);
       std::cout << m.trace() << std::endl;

       double mytrace = 0.0;
       for (int i=0; i < 80; i++)
	 {
	   mytrace += m(i,i);
	 }
       std::cout << mytrace << std::endl;
       
	 
       
       return 0; 
     }
