#include <iostream>
#include "../include/comm.h"

using namespace std;

int main(void)
{
  int i = 1234;
  int j = -567;

  cout << i << endl;
  cout.width(10);
  cout << i << endl;
  cout.width(2);
  cout << i << endl;

  cout.width(10);
  cout.fill('_');
  cout << i << endl;
  cout.fill(' ');

  cout.width(20);
  cout << left << j << endl;
  cout.width(20);
  cout << right << j << endl;
  cout.width(20);
  cout << internal << j << endl;
  return 0;
}
