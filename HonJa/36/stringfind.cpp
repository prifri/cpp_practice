#include <iostream>
#include "../include/comm.h"

using namespace std;

int main(void)
{
  string s1("string class find function");
  string s2("func");

  cout << "i:" << s1.find('i') << "nd" << endl;
  cout << "i:" << s1.find('i', 10) << "nd" << endl;
  cout << "i:" << s1.find('i', 10) << "nd" << endl;
  cout << "ass:" << s1.find("ass") << "nd" << endl;
  cout << "finding f4:" << s1.find("finding", 0, 4) << "nd" << endl;
  cout << "kiss:" << s1.find("kiss") << "nd" << endl;
  
  int ret = s1.find("kiss");
  if (ret < 0){
    cout << "kiss:" << "fail" << endl;
  }
  cout << s2 << ':' << s1.find(s2) << "nd" << endl;
  return 0;
}
