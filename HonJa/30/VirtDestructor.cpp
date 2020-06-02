#include <iostream>
#include "../include/comm.h"

using namespace std;

class Base{
  private:
    char *B_buf;

  public:
    Base(void)
    {
      B_buf = new char[10];
      puts("Base Create");
    }

    virtual ~Base(void)
    {
      delete [] B_buf;
      puts("Base Destroy");
    }
};

class Derived : public Base{
  private:
    int *D_buf;

  public:
    Derived(void)
    {
      D_buf = new int[32];
      puts("Derived Create");
    }

    virtual ~Derived(void)
    {
      delete [] D_buf;
      puts("Derived Destroy");
    }
};

int main(void)
{
#if 0
  Derived D;
#else
  Base *pB;

  pB = new Derived;
  delete pB;
#endif
  return 0;
}
