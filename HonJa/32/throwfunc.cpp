#include <iostream>
#include "../include/comm.h"

void divide(int a, int d)
{
  if (d == 0)
    throw "can't divide 0";
  printf("divide result : %d\n", a/d);
}

int main(void)
{
  try {
    divide(10, 0);
  }catch(const char *s){
    puts(s);
  }
  divide(10, 5);
//  divide(10, 0);
  try {
    divide(20, 0);
  }catch (int code){
    printf("%d error occured\n", code);
  }
  return 0;
}
