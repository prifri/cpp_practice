#include <iostream>
#include "../include/comm.h"

using namespace std;

class Date;
class Time{
  private:
  int hour, min, sec;
  public:
  Time(int h, int m, int s) : hour(h), min(m), sec(s)
  {
  }
  void out_today(Date &d);
};

class Date{
  friend void Time :: out_today(Date &d);
  private:
  int year, month, day;
  public:
  Date(int y, int m, int d) : year(y), month(m), day(d)
  {
  }

};

void Time :: out_today(Date &d)
{
  printf("today %d year, %d month, %d day, %d:%d:%d.\n",
      d.year, d.month, d.day, hour, min, sec);
}

int main(void)
{
  Date d(2005, 1, 2);
  Time t(12,34,56);

  t.out_today(d);
}
