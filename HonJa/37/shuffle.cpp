#include <iostream>
#include "../include/comm.h"
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main(void)
{
  int i;
  vector<int> vi(20);
  vector<int>::iterator it;

  for (i=0; i<20 ; i++)
    vi[i] = i;
  srand(time(NULL));
  random_shuffle(vi.begin(), vi.end());
  for (it=vi.begin(); it != vi.end() ; it++)
    printf("%d\n", *it);
  sort(vi.begin(),vi.end());
  for (it=vi.begin(); it != vi.end() ; it++)
    printf("%d\n", *it);
  return 0;
}
