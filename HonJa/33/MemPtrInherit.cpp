#include <iostream>
#include "../include/comm.h"

class A{
 public:
  int a;
  A() : a(1)
  {
  }
};

class B : public A{
 public:
  int b;
  B() : b(2)
  {
  }
};

int main(void)
{
  A a;
  B b;
  int A::*pA;
  int B::*pB;

  pA = &A::a;
//  pA = &B::b;
  pA = &B::a;
  pB = &A::a;
  pB = &B::b;
  pB = &B::a;

  printf("%d %d\n", a.*pA, b.*pB);
  return 0;
}
