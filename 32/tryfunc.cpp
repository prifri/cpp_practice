#include <iostream>
#include "../include/comm.h"

using namespace std;

void divide(int a, int d)
  try {
    if (d == 0)
      throw "abcd";
    printf("result %d\n",a/d);
  }catch (const char *msg){
    puts(msg);
  }

int main(void)
{
  return 0;
}
