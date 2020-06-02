#include <iostream>
#include "../include/comm.h"

class B
{
 public:
  void f(int a)
  {
    puts("B::f(int)");
  }

  void f(double a)
  {
    puts("B::f(double)");
  }
};

class D : public B
{
 public:
  void f(const char *a)
  {
    puts("D::f(char *)");
  }
};

int main(void)
{
  D d;
  d.f("");
#if 0
  d.f(1);
  d.f(2.3);
#endif
  return 0;
}
