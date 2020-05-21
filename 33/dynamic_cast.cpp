#include <iostream>
#include "../include/comm.h"

class Parent {
 public:
  virtual void PrintMe(void)
  {
    printf("Parent\n");
  }
};

class Child : public Parent{
 private:
  int num;
 public:
  Child(int anum=1234) : num(anum)
  {
  }
  virtual void PrintMe(void)
  {
    printf("Chld\n");
  }
  void PrintNum(void)
  {
    printf("Hello child = %d\n", num);
  }
};

int main(void)
{
  Parent P, *pP, *pP2;
  Child C, *pC, *pC2;
  pP = &P;
  pC = &C;

  pP2 = dynamic_cast<Parent *>(pC);
  pC2 = dynamic_cast<Child *>(pP2);
  printf("pC2 = %p\n", pC2);
  pC2 = dynamic_cast<Child *>(pP);
  printf("pC2 = %p\n", pC2);
  return 0;
}
