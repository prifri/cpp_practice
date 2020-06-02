#include <iostream>

#include "../include/comm.h"

class Test{
 private:
  int first;
  int second;
 public:
  Test(int a) : first(a), second(first*2)
  {
  }

  void OutMember()
  {
    printf("First = %d, second=%d\n", first, second);
  }
};

int main(void)
{
  Test t(4);

  t.OutMember();
  return 0;
}
