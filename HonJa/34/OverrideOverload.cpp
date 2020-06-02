#include <iostream>
#include "../include/comm.h"

class B
{
 public:
  void f(char * a __attribute__((unused)))
  {
    puts("B::f(char *)");
  }

  void f(long a __attribute__((unused)))
  {
    puts("B::f(long)");
  }
};

class D : public B
{
 public:
  void f(double a __attribute__((unused)))
  {
    puts("B::f(double)");
  }
};

int main(void)
{
  D d;
  d.f(1234);
  return 0;
}
