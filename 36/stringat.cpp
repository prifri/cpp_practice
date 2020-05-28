#include <iostream>
#include "../include/comm.h"

using namespace std;

int main(void)
{
  string s("korea");
  size_t len, i;

  len = s.size();

  for (i=0; i<len ; i++){
    cout << s[i];
  }

  cout << endl;
  s[0] = 'c';

  for (i=0; i<len ; i++){
    cout << s.at(i);
  }

  cout << endl;
  return 0;
}
