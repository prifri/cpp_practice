#include <iostream>
#include "../include/comm.h"

using namespace std;

class Complex{
  private:
    int real, image;
  public:
    Complex(void)
    {
    }

    Complex(int arg_real, int arg_image) : real(arg_real), image(arg_image)
    {
    }

    const Complex operator + (const Complex &r) const
    {
      return Complex(real + r.real, image + r.image);
    }

    void OutComplex(void)
    {
      printf("%d+j%d\n", real, image);
    }
};

int main(void)
{
  Complex r1(10,20), r2(30,40);
  Complex r3 = r1 + r2;

  r1.OutComplex();
  r2.OutComplex();
  r3.OutComplex();
  return 0;
}
