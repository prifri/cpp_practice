#include <iostream>
#include "../include/comm.h"

using namespace std;

class Some{

 private:
  int mem;
 public:
  Some(int m) : mem(m)
  {
    mem = m;
  }

  template <typename T>
  void memfunc(T a)
  {
    cout << "template = " << a << ", mem = " << mem << endl;
  }
};
int main(void)
{
  Some s(9999);

  s.memfunc(1234);
  s.memfunc(1.2345);
  s.memfunc("string");
  return 0;
}
