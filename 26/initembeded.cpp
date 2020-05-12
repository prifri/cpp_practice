#include <iostream>
#include "../include/comm.h"
using namespace std;

class position
{
  private:
  public:
    int x,y;
    position(int arg_x, int arg_y) : x(arg_x), y(arg_y)
  {
  }
};

class some
{
  public:
    position pos;

    some(int x, int y) : pos(x,y)
  {
  }
    void out_some(void)
    {
      cout << pos.x << " " << pos.y << endl;
    }
};

int main(void)
{
  some a(3,5);

  a.out_some();
  return 0;
}
