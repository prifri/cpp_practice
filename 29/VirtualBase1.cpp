#include <iostream>
#include "../include/comm.h"

using namespace std;

class A{
  protected:
    int a;
  public:
    A(int aa) : a(aa)
  {
  }
};

class B : virtual public A{
  protected:
    int b;
  public:
    B(int aa, int ab) : A(aa), b(ab)
  {
  }
};

class C : virtual public A{
  protected:
    int c;
  public:
    C(int aa, int ac) : A(aa), c(ac)
  {
  }
};

class D : public B, public C{
  protected:
    int d;
  public:
    D(int aa, int ab, int ac, int ad) : A(aa), B(aa, ab), C(aa, ac), d(ad)
  {
  }

    void fd(void)
    {
      b = 1;
      c = 2;
      B::a = 3;
      C::a = 4;
    }

    void Out(void)
    {
      printf("D %d, B %d, C %d, B.A %d, C.A %d\n",
          d, b, c, B::a, C::a);
    }
};

int main(void)
{
  D d(1,2,3,4);
  d.Out();
  d.fd();
  d.Out();
  return 0;
}
