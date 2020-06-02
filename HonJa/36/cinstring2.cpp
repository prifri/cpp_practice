#include <iostream>
#include "../include/comm.h"

using namespace std;

int main(void)
{
  char ch;
  char str[128];

  cin.get(ch);
  cout << ch << endl;
  cin.get(ch);

  cin.getline(str, 128);
  cout << str << endl;
  return 0;
}
