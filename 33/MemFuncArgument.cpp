#include <iostream>
using namespace std;

class Test{
 public:
  void DoCalc(void (Test::*func)(int, int) const, int a, int b)
  {
    puts("result.");
    printf("%d %d : ", a, b);
    (this->*func)(a, b);
    puts("death.");
  }

  void Op1(int a, int b) const
  {
    cout << a+b << endl;
  }

  void Op2(int a, int b) const
  {
    cout << a-b << endl;
  }

  void Op3(int a, int b) const
  {
    cout << a*b << endl;
  }
};

int main(void)
{
  int ch;
  Test t;
  int a = 3, b = 4;
  static void (Test::*func[3])(int, int) const = 
  {&Test::Op1, &Test::Op2, &Test::Op3};

  printf("select 0 = +, 1 = -, 2 = * : ");
  cin >> ch;

  if (ch >= 0 && ch <= 2)
    t.DoCalc(func[ch], a, b);
  return 0;
}
