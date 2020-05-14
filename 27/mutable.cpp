#include <iostream>
#include "../include/comm.h"

using namespace std;

class some{
  private:
    mutable int v;
  public:
    some(void)
    {
      v = 1;
    }
    void func(void) const
    {
      v = 3;
    }

    void out(void) const
    {
      cout << v << endl;
    }
};

int main(void)
{
  some a;
  a.func();

  const some b;
  b.out();
  b.func();

  b.out();
  return 0;
}
