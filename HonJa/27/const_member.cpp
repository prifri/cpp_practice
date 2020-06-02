#include <iostream>
#include "../include/comm.h"

using namespace std;

class math_calc{
  private:
#if 0
#if 0 // double형은 이렇게 안된다는데? 즉 불가능
    static const double pie = 3.141592;
#else // 이렇게만 가능하다. 근데 이건또 전역변수가 아닌 상수처럼되네?
    static const int pie = 500;
#endif
#else
    static const double pie;
#endif
  public:
    math_calc(void)
    {
    }

    void do_calc(double r)
    {
      printf("반지름 %.2f인 원의 둘레 = %.2f\n", r, r*2*pie);
      printf("pie addr %p\n", &pie);
    }
};
const double math_calc :: pie = 3.141592;

int main(void)
{
  math_calc m, a, b;
  m.do_calc(5);
  a.do_calc(5);
  b.do_calc(5);
  return 0;
}
