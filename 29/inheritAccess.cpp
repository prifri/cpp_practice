#include <iostream>
#include "../include/comm.h"

using namespace std;

class B{
  private:
    int b_pri;
    void b_fpri(void)
    {
      puts("base class private func");
    }
  protected:
    int b_pro;
    void b_fpro(void)
    {
      puts("base class protected func");
    }
  public:
    int b_pub;
    void b_fpub(void)
    {
      puts("base class public func");
    }
};

class D : public B{
  private:
    int d_pri;
    void d_fpri(void)
    {
      puts("extend class private func");
    }
  public:
    void d_fpub(void)
    {
      d_pri = 0;
      d_fpri();

#if 0
      b_pri = 1;
      b_fpri();
#endif

      b_pro = 2;
      b_fpro();

      b_pub = 3;
      b_fpub();
    }
};

int main(void)
{
  D d;

  d.d_fpub();
  d.b_fpub();
  return 0;
}
