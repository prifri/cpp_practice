#include <iostream>
#include "../include/comm.h"

using namespace std;

template <typename T>
void LongFunc(T a)
{
  printf("long function. size T %d %d\n", sizeof(T), sizeof(a));
}

int main(void)
{
  int i = 1;
  unsigned u = 2;
  long l = 3;

  LongFunc<int>(i);
  LongFunc<int>(u);
  LongFunc<int>(l);
  return 0;
}
