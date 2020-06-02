#include <iostream>
#include "../include/comm.h"

using namespace std;

template <class T>
void swap_my(T &a, T &b)
{
  T t;
  t = a;
  a = b;
  b = t;
}

template <> void swap_my<double>(double &a, double &b)
{
  int i = (int)a, j = (int)b;

  a = a - i + j;
  b = b - j + i;
}

int main(void)
{
  double a = 1.2, b = 3.4;

  printf("before a = %g, b = %g\n", a, b);
  swap_my(a, b);
  printf("after a = %g, b = %g\n", a, b);

  return 0;
}
