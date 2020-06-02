#include <iostream>
#include "../include/comm.h"

class Test{
 private:
  int *pi;
  int *pi2;

 public:
  Test(int *p) : pi(p), pi2(pi)
  {
  }

  void OutMember(void)
  {
    printf("pi %d, pi2 %d\n", *pi, *pi2);
  }
};

int g= 1234;
int main(void)
{
  Test t(&g);
  t.OutMember();
  return 0;
}
