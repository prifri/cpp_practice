#include <iostream>
#include "../include/comm.h"

class Parent{
 public:
  int a;
  Parent() : a(100)
  {
  }
};

class Child : public Parent{
 public:
  int b;
  Child() : b(99)
  {
  }
};

int main(void)
{
  Parent P, *pP;
  Child C, *pC;
  int i=1;

  pP = static_cast<Parent *>(&C);
  pC = static_cast<Child *>(&P);
#if 0
  pP = static_cast<Parent *>(&i);
  pC = static_cast<Child *>(&i);
#endif

  if (pP && pC){
    printf("%d %d %d\n", i, pC->a, pC->b);
  }
  return 0;
}
