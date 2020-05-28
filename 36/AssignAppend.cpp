#include <iostream>
#include "../include/comm.h"

using namespace std;

int main(void)
{
  string s1("12345");
  string s2("abcdefgh");
  string s3;

  s3.assign(s1,2,3);
  cout << s3 << endl;
  s3.append(s2, 4, 2);
  cout << s3 << endl;
  return 0;
}
