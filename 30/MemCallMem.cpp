#include <iostream>
#include "../include/comm.h"
#include <cmath> 

using namespace std;

class Point {
  protected:
    int x,y;
    char ch;
  public:
    Point(int ax, int ay, char ach) : x(ax), y(ay), ch(ach)
  {
  }

    virtual void Show(void)
    {
      gotoxy(x, y);
      putch(ch);
    }

    virtual void Hide(void)
    {
      gotoxy(x, y);
      putch(' ');
    }

    void Move(int nx, int ny)
    {
      Hide();
      x = nx;
      y = ny;
      Show();
    }
};

class Circle : public Point{
  protected:
    int Rad;
  public:
    Circle(int ax, int ay, char ach, int aRad) : Point(ax, ay, ach), Rad(aRad)
  {
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
  Point P(1, 1, 'P');
  Circle C(10, 10, 'C', 5);

  P.Show();
  C.Show();

  getchar();
  P.Move(40, 1);
  getchar();
  C.Move(40, 10);
  getchar();
  return 0;
}
