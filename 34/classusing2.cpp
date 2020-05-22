#include <iostream>
#include "../include/comm.h"

class B
{
 protected:
  void f(void)
  {
    puts("Base protected");
  }
 public:
  int m;
};

class D : public B
{
 protected:
  using B::m;
 public:
  using B::f;
};

class G : public D
{
 public:
  void gf(void)
  {
    m = 1234;
  }
};

int main(void)
{
  D d;
  d.f();
//  d.m=1234;
  return 0;
}
