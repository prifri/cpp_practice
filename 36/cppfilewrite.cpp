#include <iostream>
#include "../include/comm.h"
#include <fstream>

using namespace std;

int main(void)
{
  ofstream f;

  f.open("./test");
  f << "string " << 1234 << endl;
  f.close();
  return 0;
}
