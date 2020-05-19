#include <iostream>
#include "../include/comm.h"

using namespace std;

template <typename T> T cast(int s)
{
  return (T)s;
}

template <typename T> void func(void)
{
  T v;
  cin >> v;
  cout << v;
}

int main(void)
{
  unsigned i = cast<unsigned>(1234);
  double d = cast<double>(5678);

  printf("i=%d, d=%f\n", i, d);
  func<int>();
  return 0;
}
