#include <iostream>
#include "../include/comm.h"

class ConstRef
{
 public:
  int value;
  int &ri;
  const int ci;

  ConstRef(int av, int &ari, const int aci) : value(av), ri(ari), ci(aci)
  {
  }

  ConstRef &operator = (const ConstRef &Other)
  {
    if (this != &Other){
      value = Other.value;
    }
    return *this;
  }

  void ChangeRef(int &ari)
  {
    ri = ari;
  }
};

int main(void)
{
  int i = 1000, j = 4000;
  ConstRef t1(1, i, 2);
  ConstRef t2(3, j, 4);
  printf("t2 %d %d %d\n", t2.value, t2.ri, t2.ci);
  t2 = t1;
  printf("t2 %d %d %d\n", t2.value, t2.ri, t2.ci);
  t2.ChangeRef(i);
  printf("t2 %d %d %d\n", t2.value, t2.ri, t2.ci);
  return 0;
}
