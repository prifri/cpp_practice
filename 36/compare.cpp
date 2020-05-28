#include <iostream>
#include "../include/comm.h"

using namespace std;

int main(void)
{
  string s1("aaa");
  string s2("bbb");

  cout << (s1 == s1 ? "eq" : "neq") << endl;
  cout << (s2 == s1 ? "eq" : "neq") << endl;
  cout << (s1 > s2 ? "gt" : "le") << endl;

  string s3("1234567");
  string s4("1234999");

  cout << (s3.compare(s4) == 0 ? "eq" : "neq") << endl;
  cout << (s3.compare(0, 4, s4,0 ,4) == 0 ? "eq" : "neq") << endl;

  string s5("hongkildong");
  cout << (s5 == "hongkildong" ? "eq":"neq") << endl;
  return 0;
}
