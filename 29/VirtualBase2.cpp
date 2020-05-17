#include <iostream>
#include "../include/comm.h"
#include <cmath>
#include <cstring>

using namespace std;

class Coord{
  protected:
    int x, y;
  public:
    Coord(int ax, int ay) : x(ax), y(ay)
  {
  }

    void GetXY(int &rx, int &ry)
    {
      rx = x;
      ry = y;
    }

    void SetSY(int ax, int ay)
    {
      x = ax;
      y = ay;
    }
};

class Point : virtual public Coord{
  protected:
    char ch;
  public:
    Point(int ax, int ay, char ach) : Coord(ax, ay), ch(ach)
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

class Circle : public Point{
  protected:
    int Rad;
  public:
    Circle(int ax, int ay, char ach, int aRad) : Coord(ax, ay), Point(ax, ay, ach), Rad(aRad)
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

class Message : virtual public Coord
{
  private:
    char Mes[128];
    int len;
  public:
    Message(int ax, int ay, const char *M) : Coord(ax, ay)
  {
    strncpy(Mes, M, 127);
    Mes[127] = '\0';
    len = strlen(Mes);
  }

    void Show(void)
    {
      gotoxy(x - len/2, y);
      puts(Mes);
    };
};

class CirMessage : public Circle, public Message{
  public:
    CirMessage(int ax, int ay, char ach, int aRad, const char *M)
      : Coord(ax, ay), Circle(ax, ay, ach, aRad), Message(ax, ay, M)
    {
    }

    void Show(void)
    {
      Circle::Show();
      Message::Show();
    }
};

int main(void)
{
  clrscr();
  CirMessage CM(40, 10, '.', 8, "TEST");

  CM.Show();
  puts("\n\n\n");
  puts("\n\n\n");
  puts("\n\n\n");
  puts("\n\n\n");
  return 0;
}
