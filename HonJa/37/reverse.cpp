#include <iostream>
#include "../include/comm.h"
#include <vector>
#include <list>
#include <algorithm>

using namespace std;


int main(void)
{
  int ari[] = {2,8,5,1,2,7,10,9,6,3};
  int size = sizeof(ari)/sizeof(int);
  vector<int> vi(&ari[0], &ari[size]);

  sort(vi.begin(), vi.end());
  vector<int>::iterator it;

  for (it = vi.begin() ; it!= vi.end() ; it++)
    printf("%d\n", *it);

  reverse(&vi[2], &vi[6]);

  for (it = vi.begin() ; it!= vi.end() ; it++)
    printf("%d\n", *it);
  return 0;
}
