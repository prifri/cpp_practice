#include <iostream>
#include "../include/comm.h"

using namespace std;

class Test{
 public:
  void Op1(int a, int b)
  {
    cout << a+b << endl;
  }
  void Op2(int a, int b)
  {
    cout << a-b << endl;
  }
  void Op3(int a, int b)
  {
    cout << a/b << endl;
  }
};

int main(void)
{
  int ch;
  Test t;
  int a = 3, b = 4;

  printf("0=더하기, 1=빼기, 2=곱하기 : ");
  cin >> ch;

  switch (ch){
    case 0:
      t.Op1(a, b);
      break;
    case 1:
      t.Op2(a, b);
      break;
    default:
      t.Op3(a, b);
      break;
  }
  return 0;
}
