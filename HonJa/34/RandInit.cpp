#include <iostream>
#include "../include/comm.h"

class RandomInit{
 public:
  RandomInit()
  {
    std::cout << "init" << std::endl;
    srand(time(NULL));
  }
};

RandomInit Init;

int main(void)
{
  printf("hell\n");
  return 0;
};
