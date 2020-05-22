#include <iostream>
#include "../include/comm.h"

using namespace std;

class B
{
 private:
  void p(void)
  {
    puts("Base priavte");
  }
 protected:
  void f(void)
  {
    puts("Base protected");
  }
 public:
  void u(void)
  {
    puts("Base public");
  }
};

class D : public B
{
 protected:
#if 0
  using B::u;
#endif
 public:
#if 0
  using B::f;
#else
  void f(void)
  {
    B::f();
  }
#endif
};

int main(void)
{
  D d;
  d.f();
  d.u();
  return 0;
}
