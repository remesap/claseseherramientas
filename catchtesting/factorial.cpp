#include "factorial.h"

unsigned int Factorial( unsigned int number ) {
    if (0 == number) return 1;
    return number == 1 ? number : Factorial(number-1)*number;
}
