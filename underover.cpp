#include<iostream>

int main(void){


  double under = 1;
  double over = 1;

  int N = 1049;

  for (int ii=1; ii<=N ; ii++){

    under = under/2;
    over = over*2;

    std::cout << ii << "  " << under << "  " << over << std::endl;
  }
 


  return 0;
}
