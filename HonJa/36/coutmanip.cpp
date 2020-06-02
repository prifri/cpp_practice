#include <iostream>
#include "../include/comm.h"

using namespace std;

int main(void)
{
  int i= 1234;
  bool b = true;

  cout << b << endl;
  cout << boolalpha << b << endl;

  cout << hex << i << endl;
  cout << showbase << i << endl;
  cout << uppercase << i << endl;
  cout << dec << showpos << i << endl;
  return 0;
}
