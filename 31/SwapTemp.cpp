#include <iostream>
#include "../include/comm.h"

using namespace std;

template <typename T>
void Swap(T &a, T &b)
{
  T t = a;
  a = b;
  b = t;
}

struct tag_st {
  int i;
  double d;
};

int main(void)
{
  int a =3, b= 4;
  double c = 1.2, d= 3.4;
  char e = 'e', f= 'f';
  tag_st g = {1,2.3}, h = {4, 5.6};

  printf("before a = %d, b = %d\n", a, b);
  Swap(a, b);
  printf("after a = %d, b = %d\n", a, b);
  printf("before c = %f, d = %f\n", c, d);
  Swap(c, d);
  printf("after c = %f, d = %f\n", c, d);
  printf("before e = %c, f = %c\n", e, f);
  Swap(e, f);
  printf("after e = %c, f = %c\n", e, f);
  printf("before g = %d %f, h = %d %f\n", g.i, g.d, h.i, h.d);
  swap(g, h);
  printf("after g = %d %f, h = %d %f\n", g.i, g.d, h.i, h.d);
  return 0;
}

