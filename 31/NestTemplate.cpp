#include <iostream>
#include "../include/comm.h"
#include "TStack.h"

using namespace std;

template <typename T>
class PosValue{
 private:
  int x,y;
  T value;
 public:
  PosValue(void) : x(0), y(0), value(0)
  {
  }

  PosValue(int ax, int ay, T av) : x(ax), y(ay), value(av)
  {
  }
  void Outvalue(void)
  {
    gotoxy(x, y);
    cout << value << endl;
  }
};

int main(void)
{
  clrscr();

  //최신 컴파일러는 되나보다 ㅎㅎ
  TStack<PosValue<int>> sPos(10);

  PosValue<int> p1(5, 5, 123);
  PosValue<int> p2;
  sPos.Push(p1);

  p2 = sPos.Pop(NULL);
  p2.Outvalue();

  return 0;
}
