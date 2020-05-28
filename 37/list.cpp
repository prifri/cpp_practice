#include <iostream>
#include "../include/comm.h"
#include <list>

using namespace std;

int main(void)
{
  list<int> li;
  int i;

  for (i=0; i<5; i++)
    li.push_back(i*2);

  list<int>::iterator it;
  for (it=li.begin(), i=0; it != li.end() ; it++, i++)
    printf("%d %d\n", i, *it);
  return 0;
}
