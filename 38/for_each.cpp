#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(int a)
{
  printf("%d\n", a);
}

int main(void)
{
  int ari[] = {2, 3, 4, 9};

  vector<int> vi(&ari[0], &ari[sizeof(ari)/sizeof(int)]);

  sort(vi.begin(), vi.end());
  for_each(vi.begin(), vi.end(), print);
  return 0;
}
