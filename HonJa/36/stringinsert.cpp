#include <iostream>
#include "../include/comm.h"

using namespace std;

int main(void)
{
  string s1("1234567890");
  string s2("&_&");

  cout << s1 << endl;
  s1.insert(5, "XXX");
  cout << s1 << endl;
  s1.insert(5, s2);
  cout << s1 << endl;
  s1.erase(5, 6);
  cout << s1 << endl;
  return 0;
}
