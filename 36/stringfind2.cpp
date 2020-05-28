#include <iostream>
#include "../include/comm.h"

using namespace std;

int main(void)
{
  string s1("starcraft");
  string s2("123abc456");
  string moum("aeiou");
  string num("0123456789");

  cout << ">> t:" << s1.find('t') << "nd" << endl;
  cout << "<< t:" << s1.rfind('t') << "nd" << endl;
  cout << "<< cra:" << s1.rfind("cra") << "nd" << endl;
  cout << "first" << s1.find_first_of(moum) << "nd" << endl;
  cout << "last" << s1.find_last_of(moum) << "nd" << endl;
  cout << "not first" << s2.find_first_not_of(num) << "nd" << endl;
  cout << "not last" << s2.find_last_not_of(num) << "nd" << endl;
  return 0;
}
