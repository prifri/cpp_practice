#include <iostream>
#include "../include/comm.h"

using namespace std;

class B{
  public:
    int m;
    B(int am) : m(am)
  {
  }
    void f(void)
    {
      puts("Base function");
    }
};

class D : public B {
  public:
    int m;
    D(int dm, int bm) : B(bm), m(dm)
  {
  }
    void f(void)
    {
      puts("Derived function");
    }
};

int main(void)
{
  D d(1, 2);
  printf("d.m = %d\n", d.m);
  d.f();

  printf("d.m = %d\n", d.B :: m);
  d.B::f();
  return 0;
}
