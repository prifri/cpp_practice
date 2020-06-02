#include <iostream>
#include "../include/comm.h"

using namespace std;

int main(void)
{
  int i;

  cin >> i;
  if (cin.good())
    cout << "good" << endl;
  if (cin.fail())
    cout << "fail" << endl;
  if (cin.eof())
    cout << "eof" << endl;
  if (cin.bad())
    cout << "bad" << endl;
  return 0;
}
