#include <iostream>
#include "../include/comm.h"

using namespace std;;

class Coord{
  protected:
    int x,y;
  public:
    Coord(int arg_x, int arg_y) : x(arg_x), y(arg_y)
    {
    }
    void GetXY(int &rx, int &ry)
    {
      rx = x;
      ry = y;
    }
    void SetXY(int arg_x, int arg_y)
    {
      x = arg_x;
      y = arg_y;
    }
};

class Point : public Coord{
  protected:
    char ch;
  public:
    Point(int arg_x, int arg_y, char arg_ch) : Coord(arg_x, arg_y), ch(arg_ch)
    {
    }
    void Show(void)
    {
      gotoxy(x, y);
      putch(ch);
    }
    void Hide(void)
    {
      gotoxy(x, y);
      putch(' ');
    }
};

int main(void)
{
  clrscr();

  Point P(10, 10, '@');
  P.Show();
  return 0;
}
