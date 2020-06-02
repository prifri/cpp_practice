#include <iostream>
#include <fstream>
#include "../include/comm.h"

using namespace std;

int main(void)
{
  ifstream f;

  f.open("neverexist");
  if (f.is_open()){
    cout << "success" << endl;
    f.close();
  }
  else
    cout << " fail" << endl;
  return 0;
}
