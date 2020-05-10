#include <iostream>
#include "../include/comm.h"

class position{
  private:
    int x, y;
    char ch;
  public:
    position(char ach)
    {
      x = y = 21;
      ch = ach;
    }

    position(int ax = 1, int ay = 2, char ach = 'z')
    {
      x = ax;
      y = ay;
      ch = ach;
    }

    void out_pos(void)
    {
      gotoxy(x, y);
      putch(ch);
    }
};

int main(void)
{
  position pos(10,20,'a');
  position pos2(5);
  pos.out_pos();
  pos2.out_pos();
  return 0;
}
