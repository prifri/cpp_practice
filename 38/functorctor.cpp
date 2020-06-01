#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "../include/comm.h"

using namespace std;

struct print{
  string mes;
  print(const string &m) : mes(m)
  {
  }

  void operator()(int a) const
  {
    cout << mes;
    printf("%d\n", a);
  }
  
};

int main(void)
{
  int ari[] = {2,8,5,1,9};

  vector<int> vi(ari, &ari[sizeof(ari)/sizeof(int)]);

  sort(vi.begin(), vi.end());
  for_each(vi.begin(), vi.end(), print(string("member ")));
  for_each(vi.begin(), vi.end(), print(string("othrer " )));
  return 0;
}
