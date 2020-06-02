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

using namespace MYNS;
int main(void)
{
  func();
  return 0;
}
