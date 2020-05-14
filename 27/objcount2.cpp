#include <iostream>
#include "../include/comm.h"
#include <atomic>

using namespace std;

class count{
  private:
    static atomic<int> num;
  public:
    count(void)
    {
      num.fetch_add(1);
    }
    ~count(void)
    {
      num.fetch_add(-1);
    }

    static void init_count(void)
    {
      num = 0;
    }

    static void out_count(void)
    {
      cout << "current obj cnt : " << num << endl;
    }
};

atomic<int> count :: num;

int main(void)
{
  count :: init_count();
  count :: out_count();
  count a, b, c;
  count *p = new count;

  a.out_count();
  p->out_count();
  delete p;
  p->out_count();
  return 0;
}
