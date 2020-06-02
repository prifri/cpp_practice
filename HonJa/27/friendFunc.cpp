#include <iostream>
#include "../include/comm.h"

using namespace std;

class Date;
class Time{
  friend void out_today(Date &d, Time &t);
  private:
  int hour, min, sec;
  public:
  Time(int h, int m, int s) : hour(h), min(m), sec(s)
  {
  }
};

class Date{
  friend void out_today(Date &d, Time &t);
  private:
  int year, month, day;
  public:
  Date(int y, int m, int d) : year(y), month(m), day(d)
  {
    day = d;
  }
};

void out_today(Date &d, Time &t)
{
  printf("today %d year, %d month, %d day, %d:%d:%d.\n",
      d.year, d.month, d.day, t.hour, t.min, t.sec);
}

int main(void)
{
  Date d(2005, 1, 2);
  Time t(12,34,56);

  out_today(d, t);
}
