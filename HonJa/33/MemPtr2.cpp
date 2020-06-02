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
  static void ((Test::*arpo[3])(int, int)) =
  {&Test::Op1, &Test::Op2, &Test::Op3};

  printf("0=더하기, 1=빼기, 2=곱하기 : ");
  cin >> ch;

  if (ch >= 0 && ch <=2)
    (t.*arpo[ch])(a, b);
  return 0;
}
