#include <iostream>
#include "../include/comm.h"

using namespace std;

class Base{
  public:
    virtual void OutMessage(void)
    {
      printf("Base Class\n");
    }
};

class Derived : public Base{
  public:
    virtual void OutMessage(void)
    {
      printf("Derived Class\n");
    }
};

int main(void)
{
  Base B, *pB;
  Derived D;

  pB = &B;
  pB->OutMessage();
  pB = &D;
  pB->OutMessage();
  return 0;
}
