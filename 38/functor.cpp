#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct print{
  void operator()(int a) const
  {
    printf("%d\n", a);
  }
};

int main(void)
{
  int ari[] = {2,3,4,1,8};
  
  vector<int> vi(ari, &ari[sizeof(ari)/sizeof(int)]);

  sort(vi.begin(), vi.end());
  for_each(vi.begin(), vi.end(), print());
  return 0;
}
