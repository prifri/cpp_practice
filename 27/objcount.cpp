#include <iostream>
#include "../include/comm.h"

using namespace std;

class count{
  private:
    static int num;
  public:
    count(void)
    {
      num++;
    }
    ~count(void)
    {
      num--;
    }
    void out_count(void)
    {
      cout << "current obj cnt : " << num << endl;
    }
};

int count :: num = 0;
int main(void)
{
  count a, b, c;

  a.out_count();
  return 0;
}
