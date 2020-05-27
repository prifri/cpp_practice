#include <iostream>
#include <string>
#include "../include/comm.h"
using namespace std;

int main(void)
{
  string s("C++ string");

  s.c_str[1] = '\0';
  cout << s << "size = " << s.size() << endl;
  cout << s << "len = " << s.length() << endl;
  cout << s << "capacity = " << s.capacity() << endl;
  cout << s << "max_len = " << s.max_size() << endl;

  s.resize(6);
  cout << s << "len = " << s.length() << endl;
  cout << s << "capacity = " << s.capacity() << endl;

  s.reserve(100);
  cout << s << "len = " << s.length() << endl;
  cout << s << "capacity = " << s.capacity() << endl;
  return 0;
}
