#include <iostream>
#include "../include/comm.h"
#include <cmath>

using namespace std;

class Coord{
  protected:
    int x,y;
  public:
    Coord(int arg_x, int arg_y) : x(arg_x), y(arg_y)
    {
      puts("coord init\n");
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
    Point(int ax, int ay, int ach) : Coord(ax, ay), ch(ach)
    {
      puts("Pooint init\n");
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

class Circle : public Point{
  protected:
    int Rad;
  public:
    Circle(int ax, int ay, char ach, int aRad) : Point(ax, ay, ach), Rad(aRad)
    {
      puts("Circle init\n");
    }

    void Show(void)
    {
      for (double a=0; a<360; a+= 15){
        gotoxy(int (x+sin(a*3.14/180)*Rad), int(y-cos(a*3.14/180)*Rad));
        putch(ch);
      }
    }

    void Hide(void)
    {
      for (double a=0; a<360; a+= 15){
        gotoxy(int (x+sin(a*3.14/180)*Rad), int(y-cos(a*3.14/180)*Rad));
        putch(' ');
      }
    }
};

int main(void)
{
  clrscr();

  Point P(10, 10, '@');
  P.Show();
  Circle C(40, 10, '*', 8);
  C.Show();
  return 0;
}
