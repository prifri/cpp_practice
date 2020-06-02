#include <iostream>

class A{
 public:
  int &ri;
  static int a;
  A(int &i) : ri(i)
  {
  }
};
int A::a = 4;

int main(void)
{
  int num = 3;
  A a(num);
  int *pi;

#if 0
  int A::*pa;
  pa = &A::ri;
  pa = &A::a;
#endif
  pi = &A::a;
  printf("%d %d\n", *pi, a.ri);
  return 0;
}
