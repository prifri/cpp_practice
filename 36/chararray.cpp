#include <iostream>
#include "../include/comm.h"
#include <string>
#include <cstring>

using namespace std;

int main(void)
{
  string s("char array");

  cout << s.data() << endl;
  cout << s.c_str() << endl;

  char str[128];
  strcpy(str, s.c_str());
  printf("str = %s\n", str);
  return 0;
}
