#include <iostream>
#include "../include/comm.h"
#include <vector>

using namespace std;

int main(void)
{

  int ari[] = {1,2,3,4,5};
  vector<int> vi(&ari[0], &ari[5]);

  vector<int>::iterator it;

  for (it=vi.begin() ; it!=vi.end() ; it++)
    printf("%d\n", *it);
  return 0;
}
