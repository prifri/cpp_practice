#include <iostream>
#include "../include/comm.h"

using namespace std;

int main(void)
{
  string s("1234567890");
  char str[128] = "abcdefghijkmnpopqrstuvwxyz";

  s.copy(str, 5, 3);

  cout << str << endl;

  string s1("dog");
  string s2("cow");

  cout << "s1:" << s1 << "s2:" << s2 << endl;
  s1.swap(s2);
  cout << "s1:" << s1 << "s2:" << s2 << endl;
  return 0;
}
