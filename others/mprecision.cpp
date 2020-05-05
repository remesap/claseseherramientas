#include<iostream>
#include<cmath>

int main(void){

  double eps = 1;
  double one = 1;
  int N = 20;
  
  for(int ii=1; ii <= N ; ii++){

    eps = eps/2;
    one = 1 + eps;

    std::cout<< ii << "  " << one << "  " << eps << std::endl;

  }
  
  return 0;

}
