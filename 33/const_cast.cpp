#include <iostream>
#include "../include/comm.h"

int main(void)
{
  char str[] = "string";
  const char *c1 = str;
  char *c2;

  c2 = const_cast<char *>(c1);
  c2[0] = 'a';

  printf("%s\n", c2);
  return 0;
}
