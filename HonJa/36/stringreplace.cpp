#include <iostream>
#include "../include/comm.h"

using namespace std;

int main(void)
{
  string s1 = "1234567890";

  cout << s1 << endl;
  s1.replace(7,4, "a");
  cout << s1 << endl;
  return 0;
}
