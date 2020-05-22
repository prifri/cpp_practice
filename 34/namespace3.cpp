#include <iostream>
#include "../include/comm.h"

int i;

namespace A{
int i;
}

int main(void)
{
  int i;

  i = 1;
  ::i = 2;
  A::i = 3;

  printf("%d %d %d\n", i, ::i, A::i);
  return 0;
}
