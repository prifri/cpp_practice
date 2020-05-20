#include <iostream>
#include "../include/comm.h"

using namespace std;

class C{
  int a;
 public:
  C(void)
  {
    puts("C init");
  }
  ~C(void)
  {
    puts("C deinit");
  }
};

void divide(int a, int d)
{
  if (d == 0)
    throw "can't divide 0";
  printf("divide result : %d\n", a/d);
}

void calc(int t __attribute__((unused)),
          const char *m __attribute__((unused)))
{
  C c;
  divide(10, 0);
}

int main(void)
{
  try {
    calc(1, "cal");
  }catch (const char *msg){
    puts(msg);
  }
  puts("program exit");
  return 0;
}
