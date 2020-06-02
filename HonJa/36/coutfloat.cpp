#include <iostream>
#include "../include/comm.h"

using namespace std;

int main(void)
{
  double d = 1.234;

  cout << d << endl;
  cout.precision(3);
  cout << d << endl;
  cout.precision(10);
  cout << showpoint << d << endl;
  cout.precision(6);

  cout << fixed << d << endl;
  cout << scientific << d << endl;
  return 0;
}
