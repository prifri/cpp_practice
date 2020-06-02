#include <iostream>
#include "../include/comm.h"

using namespace std;

class Base
{
 private:
  int num;
 public:
  virtual void OutMessage(void)
  {
    printf("Base\n");
  }
};

class Derived : public Base
{
 private:
  int dnum;
 public:
  virtual void OutMessage(void)
  {
    printf("Derived\n");
  }
};

int main(void)
{
  Derived arD[5];
  int i;

  Base *pB[5];

  for (i=0; i<5 ; i++){
    pB[i] = &arD[i];
    pB[i]->OutMessage();
  }
  return 0;
}
