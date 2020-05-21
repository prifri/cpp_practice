#include <iostream>
#include "../include/comm.h"

class Position{
 public:
  int x,y;
  char ch;

  Position(void) : x(0), y(0), ch('A')
  {
  }

  void OutPosition(void)
  {
    gotoxy(x, y);
    putch(ch);
  }
};

int main(void)
{
  Position Here;
  Position *pPos = &Here;
  int Position::*pi;

  clrscr();

  pPos->OutPosition();
  delay_ms(1000);
  pi = &Position::x;
  pPos->*pi = 30;
  pPos->OutPosition();
  delay_ms(1000);
  pPos->*pi = 50;
  pPos->OutPosition();

  return 0;
}
