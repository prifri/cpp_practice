#include <iostream>
#include "../include/comm.h"

using namespace std;

class Time{
  private:
    int hour, min, sec, t_sec;
  public:
    Time(void)
    {
    }

    Time(int ah, int am, int as) :
      hour(ah), min(am), sec(as)
    {
      t_sec = hour*60*60 + min*60 + sec;
    }

    Time(int ats) : t_sec(ats)
    {
      sec = ats%60;
      ats /= 60;
      min = ats%60;
      hour = ats/60;
    }

    void OutTime(void)
    {
      printf("%02d:%02d:%02d\n", hour, min, sec);
    }

    operator int()
    {
      return t_sec;
    }

    Time &operator +=(int ats)
    {
      t_sec += ats;
      ats = t_sec;
      sec = ats%60;
      ats /= 60;
      min = ats%60;
      hour = ats/60;
      return *this;
    }

    const Time operator +(int ats)const
    {
      Time t = *this;
      t += ats;
      return t;
    }
};

int main(void)
{
  Time t1(1,2,3);

  t1.OutTime();
  t1 += 3;
  t1.OutTime();
  t1 = t1 + 3;
  t1.OutTime();
  t1 = 3 + t1;
  t1.OutTime();
  return 0;
}
