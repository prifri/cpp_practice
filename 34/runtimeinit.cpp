#include <iostream>
#include "../include/comm.h"

int randinit(void)
{
  printf("go\n");
  srand(time(NULL));
  return 0;
}

int g_r = randinit();

int main(void)
{
  printf("%d\n", random(100));
  return 0;
}
