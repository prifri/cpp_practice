#include <iostream>
#include "../include/comm.h"

using namespace std;

class pos{
  private:
    int x, y;
    char ch;
  public:
    pos(int a_x, int a_y, char a_ch) : x(a_x), y(a_y), ch(a_ch)
    {
    }

    void out_pos(void) const
    {
      gotoxy(x, y);
      putch(ch);
    }

    void move_to(int a_x, int a_y)
    {
      x = a_x;
      y = a_y;
    }
};

int main(void)
{
  clrscr();

  pos here(1, 2, 'a');
  here.move_to(3,2);
  here.out_pos();

  const pos there(3, 4, 'b');
  //there.move_to(40,10);
  there.out_pos();
  return 0;
}
