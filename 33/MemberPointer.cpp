#include <iostream>
#include "../include/comm.h"

class MyClass{
 public:
  int i,j;
  double d;
  MyClass(void) : i(1), j(2), d(3.3)
  {
  }
};


int main(void)
{
  MyClass C;
  int MyClass::*pi;
  double MyClass::*pd;

  pi = &MyClass::i;
  printf("i %d\n", C.*pi);
  pi = &MyClass::j;
  printf("j %d\n", C.*pi);
  pd = &MyClass::d;
  printf("d %g\n", C.*pd);
  return 0;
}
