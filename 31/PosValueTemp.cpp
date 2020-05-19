#include <iostream>
#include "../include/comm.h"

using namespace std;

template <typename T>

class PosValue{
  private:
    int x,y;
    T value;
  public:
    PosValue(int ax, int ay, T av) : x(ax), y(ay), value(av)
  {
  }
    void OutValue(void);
};

template <typename T>
void PosValue<T> :: OutValue(void)
{
  gotoxy(x, y);
  cout << value;
}

int main(void)
{
  PosValue<int> iv(1, 1,2);
  PosValue<char> cv(5, 1,'c');
  PosValue<double> dv(30,2,3.14);

  clrscr();
  iv.OutValue();
  cv.OutValue();
  dv.OutValue();

  putch('\n');
  putch('\n');
  putch('\n');
  putch('\n');
  putch('\n');
  return 0;
}
