#include <iostream>
#include "../include/comm.h"

using namespace std;

class Base{
  public:
    virtual void OutMessage(void) const
    {
      printf("Base Class\n");
    }
};

class Derived : public Base{
  public:
    virtual void OutMessage(void) const
    {
      printf("Derived Class\n");
    }
};

void Message(const Base *pB)
{
  pB->OutMessage();
}

int main(void)
{
  Base B;
  Derived D;

  Message(&B);
  Message(&D);
  return 0;
}
