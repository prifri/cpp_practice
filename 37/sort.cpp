#include <iostream>
#include "../include/comm.h"
#include <vector>
#include <list>
#include <algorithm>

using namespace std;


int main(void)
{
  int ari[] = {2,8,5,1,2,7,2};
  vector<int> vi(&ari[0], &ari[sizeof(ari)/sizeof(int)]);

  sort(vi.begin(), vi.end());
  vector<int>::iterator it;

  for (it = vi.begin() ; it!= vi.end() ; it++)
    printf("%d\n", *it);
  return 0;
}
