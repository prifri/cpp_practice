#include <iostream>
#include "../include/comm.h"

using namespace std;

template <typename T>
T MAX(T a, T b)
{
  return (a > b) ? a : b;
}

struct S{
  int i;
  S(int ai) : i(ai)
  {
  }

  bool operator > (const S &s) const
  {
    return i > s.i;
  }
};

int main(void)
{
  int i1 = 3, i2 = 4;
  double d1 = 1.2, d2 = 3.4;
  S s1(1), s2(2);

  printf("i %d\n", MAX(i1, i2));
  printf("d %f\n", MAX(d1, d2));
  printf("s %d\n", MAX(s1, s2).i);
  return 0;
}
