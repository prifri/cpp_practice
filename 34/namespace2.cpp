#include <iostream>
#include "../include/comm.h"

namespace A{
double i;
}

namespace B{
int i;
}

void func(void)
{
  A::i = 3.14;
  B::i = 1;
  printf("%g %d\n", A::i, B::i);
}

int main(void)
{
  func();
  return 0;
}
