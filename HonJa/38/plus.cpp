#include <iostream>
#include "../include/comm.h"
#include <functional>

using namespace std;

int main(void)
{
  plus<int> add;
  int a = 1, b = 2;
  int c = add(a, b);
  cout << c << endl;
  return 0;
}
