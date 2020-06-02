#include <iostream>
#include "../include/comm.h"

class position{
  private:
    int x, y;
    char ch;
  public:
    position(int ax, int ay, char ach = 'z')
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
  pos.out_pos();
  return 0;
}
