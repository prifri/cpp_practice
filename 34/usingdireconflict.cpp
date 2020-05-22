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
  using namespace MYNS;
  int value = 3;

  value = 1;
  ::value = 2;
  MYNS::value = 3;
  return 0;
}
