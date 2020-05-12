#include <iostream>
#include "../include/comm.h"
using namespace std;

class some
{
  private:
    const int value;
  public:
    some(int i) : value(i)
    {
    }

    void out_some(void)
    {
      cout << value << endl;
    }
};

int main(void)
{
  some a(1);
  a.out_some();
  return 0;
}
