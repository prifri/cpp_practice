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

void sub(void)
{
  MYNS::func();
}
        
int main(void)
{
  using MYNS::func;

  func();
  return 0;
}
