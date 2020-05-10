#include <iostream>
#include "../include/comm.h"

using namespace std;

class time_class{
  private:
    int h,m,s;
  public:
    void set_time(int __h, int __m, int __s)
    {
      h = __h;
      m = __m;
      s = __s;
    }
    void out_time(void)
    {
      cout << "current time : " << h << ":" << m << ":" << s << endl;
    }
};

int main(void)
{
  time_class t;
  t.set_time(10, 20, 30);
  t.out_time();
  return 0;
}
