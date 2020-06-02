#include <iostream>
#include "../include/comm.h"
#include <list>
#include <vector>

using namespace std;

template<typename IT>
void Print(IT s, IT e)
{
  IT it;
  for (it=s ; it!=e ; it++)
    printf("%d\n", *it);
}

int main(void)
{
  int ari[] = {1,2,3,4,5};
  vector<int> vi(&ari[0], &ari[5]);
  list<int> li(&ari[0], &ari[5]);

  Print(&ari[0], &ari[5]);
  Print(vi.begin(), vi.end());
  Print(li.begin(), li.end());
  return 0;
}
