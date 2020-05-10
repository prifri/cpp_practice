#include <iostream>
using namespace std;

int main()
{
  int *p = new int;
  if (p){
    *p = 123;
    cout << *p << endl;
    delete p;
  }
  else
    cout << "alloc error" << endl;
  return 0;
}
