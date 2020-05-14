#include <iostream>
#include "../include/comm.h"

using namespace std;

class enemy{
  private:
    const int speed;
  public:
    enemy(int arg_speed) : speed(arg_speed)
    {
    }

    void move(void) const
    {
      printf("%d\n", speed);
    }
};

int main(void)
{
  enemy a(10), b(20);

  a.move();
  b.move();
  return 0;
}
