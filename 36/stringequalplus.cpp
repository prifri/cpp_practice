#include <iostream>
#include "../include/comm.h"

using namespace std;

int main(void)
{
  string s1("abc");
  string s2;

  s2 = "12345";
  cout << s1 << endl;
  cout << s2 << endl;

  s2 = s1;
  cout << s2 << endl;

  s2 = 'a';
  cout << s2 << endl;

  s1 + "string.";
  cout << s1 << endl;

  s1 += s2;

  cout << s1 << endl;

  s1 += '!';

  cout << s1 << endl;

  string s3 = "s1:"+s1+"s2:"+s2+'.';
  cout << s3 << endl;
  return 0;
}
