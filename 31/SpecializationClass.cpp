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

  void OutValue();
};

template <typename T>
void PosValue<T> :: OutValue(void)
{
  gotoxy(x, y);
  cout << value << endl;
}

struct tag_Friend{
  char Name[10];
  int Age;
  double Height;
};

template <>
class PosValue<tag_Friend>
{
 private:
  int x,y;
  tag_Friend value;
 public:
  PosValue(int ax, int ay, tag_Friend av) : x(ax), y(ay), value(av)
  {
  }
  void OutValue();
};

void PosValue<tag_Friend> :: OutValue()
{
  gotoxy(x, y);
  cout << "Nmae:" << value.Name << ". age:" << value.Age
      << ", 키:" << value.Height << endl;
}

int main(void)
{
  clrscr();

  PosValue<int> iv(1, 1, 2);
  tag_Friend F={"ABC", 25, 177.3};
  PosValue<tag_Friend> fv(2, 2, F);
  iv.OutValue();
  fv.OutValue();
  return 0;
}
