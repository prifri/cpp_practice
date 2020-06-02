#include <iostream>
#include "../include/comm.h"

int main(void)
{
  const char *str = "korea";
  int *pi;
  double d=123.456;
  int i;

  i = static_cast<int>(d);
//  pi = static_cast<int *>(str);
  pi = (int *)str;

  printf("i %d pi %d str %s\n", i, *pi, str);
  return 0;
}
