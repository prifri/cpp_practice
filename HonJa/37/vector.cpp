#include <iostream>
#include "../include/comm.h"
#include <vector>

using namespace std;

int main(void)
{
  int num;
  int i;

  printf("in arr size : ");
  cin >> num;

  if (num > 10000){
    printf("err\n");
    return 0;
  }

  vector<int> vi(num);

  for (i=0 ; i<num ; i++)
    vi[i] = i*2;

  for (i=0 ; i <num ; i++)
    printf("%d = %d\n", i, vi[i]);

  printf("vector size is %d\n", vi.size());
  return 0;
}
