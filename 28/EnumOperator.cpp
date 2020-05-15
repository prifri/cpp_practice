#include <iostream>
#include "../include/comm.h"

using namespace std;

enum origin{
  EAST,
  WEST,
  SOUTH,
  NORTH
};

origin &operator ++(origin &o)
{
  if (o != NORTH){
    o = origin(o+1);
  }
  else {
    o = EAST;
  }
  return o;
}

int main(void)
{
  origin o = WEST;

  for (int i=7 ; i>=0 ; i--){
    printf("%d\n",++o);
  }
  return 0;
}
