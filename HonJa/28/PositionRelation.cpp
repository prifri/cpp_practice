#include <iostream>
#include "../include/comm.h"

using namespace std;
class Pos{
  private:
    int x, y;
    char ch;
  public: 
    Pos(int ax, int ay, char ach = ' ') : x(ax), y(ay), ch(ach)
    {
    }

    void Out(void)
    {
      gotoxy(x, y);
      putch(ch);
    }

    const bool operator < (const Pos &p) const
    {
      if (y < p.y)
        return true;
      else if (y > p.y)
        return false;
      else if (x < p.x)
        return true;
      return false;
    }

    const bool operator == (const Pos &p) const
    {
      if (y == p.y && x == p.x)
        return true;
      return false;
    }

    const bool operator > (const Pos &p) const
    {
      return !(*this < p);
    }

    const bool operator != (const Pos &p) const
    {
      return (*this == p);
    }

    const bool operator <= (const Pos &p) const
    {
      return (*this == p) || (*this < p);
    }

    const bool operator >= (const Pos &p) const
    {
      return !(*this <= p);
    }
};

int main(void)
{
  Pos p1(3,4), p2(3,4);

  if (p1 == p2)
    printf("p1 == p2\n");
  else
    printf("p1 != p2\n");
  return 0;
}
