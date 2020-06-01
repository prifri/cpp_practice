#include <iostream>
#include "../include/comm.h"
#include <vector>
#include <algorithm>

using namespace std;

struct  accum{
  int sum;
  accum()
  {
    sum = 0;
  }

  void operator()(int a)
  {
    sum += a;
  }
};

int main(void)
{
  int ari[] = {2, 8, 5, 1, 9};

  vector<int> vi(ari, &ari[sizeof(ari)/sizeof(int)]);

  sort(vi.begin(), vi.end());

  accum f;

  f = for_each(vi.begin(), vi.end(), f);
  printf("sum = %d\n", f.sum);
  return 0;
}
