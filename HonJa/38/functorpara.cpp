#include <iostream>
#include "../include/comm.h"

using namespace std;

template <typename T>
class SomeClass{
  T test;
 public:
  void out(int a)
  {
    test(a);
  }

};

struct print{
  void operator()(int a) const
  {
    printf("%d\n", a);
  }
};

void func(int a)
{
  printf("%d\n", a);
}

int main(void)
{
  SomeClass<print> s1;
  s1.out(10);
  return 0;
}
