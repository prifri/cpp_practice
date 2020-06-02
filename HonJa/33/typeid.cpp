#include <iostream>
#include <typeinfo>
#include "../include/comm.h"

class Parent{
 public:
  virtual void PrintMe()
  {
    printf("Parent\n");
  }
};

class Child : public Parent {
 private:
  int num;

 public:
  Child(int anum = 1234) : num(anum)
  {
  }
  virtual void PrintMe()
  {
    printf("Child\n");
  }
  void PrintNUm()
  {
    printf("Hello child = %d\n", num);
  }

};

int main(void)
{
  Parent P, *pP;
  Child C, *pC;
  pP = &P;
  pC = &C;

  printf("P=%s, pP= %s, *pP=%s\n",
         typeid(P).name(), typeid(pP).name(), typeid(*pP).name());
  printf("P=%s, pP= %s, *pP=%s\n",
         typeid(C).name(), typeid(pC).name(), typeid(*pC).name());

  pP=&C;
  printf("P=%s, pP= %s, *pP=%s\n",
         typeid(P).name(), typeid(pP).name(), typeid(*pP).name());
  return 0;
}
