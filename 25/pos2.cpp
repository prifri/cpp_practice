#include <iostream>
#include "../include/comm.h"

using namespace std;

struct position{
  int x;
  int y;
  char ch;

  void outposition(void)
  {
    gotoxy(x, y);
    putch(ch);
  }
};

int main()
{
  position here;
  here.x = 30;
  here.y = 10;
  here.ch = 'a';
  here.outposition();
  return 0;
}
