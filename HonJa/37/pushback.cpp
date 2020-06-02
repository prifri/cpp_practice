#include <iostream>
#include "../include/comm.h"
#include <vector>

using namespace std;

int main(void)
{
  int num = 10;
  int i;

  vector<int> vi;

  for (i=0 ; i<num ; i++)
    vi.push_back(i*2);

  for (i=0 ; i <num ; i++)
    printf("%d = %d\n", i, vi[i]);

  printf("vector size is %d\n", vi.size());
  return 0;
}
