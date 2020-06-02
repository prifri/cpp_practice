#include <iostream>
#include "../include/comm.h"
using namespace std;

class some
{
  private:
    int &ri;
  public:
    some(int &i) : ri(i)
    {
    }

    void out_some(void)
    {
      cout << ri << endl;
      printf("out value addr 0x%p\n", &ri);
    }

    void up_value(void)
    {
      ri++;
    }
};

int main(void)
{
  int val = 3;
  printf("main valu addr 0x%p\n", &val);
  some a(val);
  a.out_some();
  a.up_value();
  printf("up value %d\n", val);
  a.out_some();
  return 0;
}
