#include <iostream>
#include "../include/comm.h"

using namespace std;

class Sum
{
  public:
    int operator()(int a, int b, int c, int d)
    {
      return a + b + c + d;
    }
    const double operator ()(double a, double b)
    {
      return a+b;
    }
};

int main(void)
{
  Sum S;

  printf("%d %f\n", S(1,2,3,4), S(1.2, 3.4));
  return 0;
}
