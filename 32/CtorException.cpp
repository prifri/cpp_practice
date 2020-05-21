#include <iostream>
#include "../include/comm.h"

using namespace std;

class int100
{
 private:
  int num;
 public:
  int100(int a)
  {
    if (a <= 100)
      num = a;
    else
      throw a;
  }
  int100 operator +=(int b)
  {
    if (num + b <= 100){
        num += b;
        return *this;
    }
    else
      throw num+b;
  }

  void OutValue(void)
  {
    printf("%d\n", num);
  }
};

int main(void)
{
  try {
    int100 i(85);
    i += 99;
    i.OutValue();
  }catch (int n){
    printf("%d gt 100. invalid\n", n);
  }
  return 0;
}
