#include <iostream>
#include "../include/comm.h"
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main(void)
{
  int ari[] = {1,2,3,4,5};
  vector<int> vi(&ari[0], &ari[5]);
  list<int> li(&ari[0], &ari[5]);

  puts(find(vi.begin(), vi.end(), 4) == vi.end() ? "n" : "y");
  puts(find(li.begin(), li.end(), 8) == li.end() ? "n" : "y");
  puts(find(&ari[0], &ari[5], 3) == &ari[5] ? "n" : "y");
  return 0;
}
