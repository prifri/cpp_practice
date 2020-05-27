#include <iostream>
#include "../include/comm.h"

using namespace std;

int main(void)
{
  int i =1234;

  hex(cout);
  cout << i << endl;
  cout << oct << i << endl;
  cout << dec << i << endl;
  return 0;
}
