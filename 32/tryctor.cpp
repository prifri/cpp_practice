#include <iostream>
#include "../include/comm.h"

using namespace std;

class Position{
 private:
  int x,y;
  char ch;
 public:
  Position(int ax, int ay, int ach)
      try : x(ax), y(ay), ch(ach) {
    if (ax < 0)
      throw ax;
    if (ay < 0)
      throw ay;
    if (isdigit(ach) == 0)
      throw ach;
  }catch (int a){
    printf("invalid x or y %d\n", a);
  }catch (char ch){
    printf("invalid ch %d\n", ch);
  }

  void OutPosition(void)
  {
    gotoxy(x, y);
    putch(ch);
  }
};

int main(void)
{
  try {
    Position Here(1, 10, 3);
    Here.OutPosition();
  }catch (int){
    puts("invalid object int");
  }catch (char){
    puts("invalid object ch");
  }
  return 0;
}
