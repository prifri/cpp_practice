#include <iostream>
#include "../include/comm.h"

namespace MYNS {

int value;
double score;
void func(void)
{
  printf("func\n");
}

}

int value;
int main(void)
{
  using MYNS::value;
  int value=3;

  value = 1;
  ::value = 2;
  return 0;
}
