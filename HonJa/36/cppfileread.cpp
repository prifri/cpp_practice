#include <iostream>
#include "../include/comm.h"
#include <fstream>
using namespace std;

int main(void)
{
  ifstream f;
  char str[128];
  int i;

  f.open("./test");
  f >> str >> i;
  cout << str << i << endl;
  f.close();
  return 0;
}
