#include <iostream>
#include "../include/comm.h"
#include <cstdlib>

using namespace std;

class SomeClass
{
 public:
  int a;
  SomeClass(void) : a(1) {}
};

void calc(void) throw(int)
{
  SomeClass obj;
  char *p = (char *)malloc(1000);

  if (true){
    free(p);
    throw 1;
  }
}

int main(void)
{
  try {
    calc();
  }catch (int){
    puts("abc");
  }

  return 0;
}
