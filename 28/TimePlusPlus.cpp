#include <iostream>
#include "../include/comm.h"

using namespace std;

class Time{
  private:
    unsigned hour, min, sec, t_sec;
  public:
    Time(void)
    {
    }

    Time(unsigned ah, unsigned am, unsigned as) :
      hour(ah), min(am), sec(as)
    {
      t_sec = hour*60*60 + min*60 + sec;
    }

    Time(unsigned ats) : t_sec(ats)
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

    operator unsigned()
    {
      return t_sec;
    }

    const Time operator +(const Time &t) const
    {
      return Time(t_sec+t.t_sec);
    }
    const Time operator +(int s) const
    {
      return Time(t_sec+s);
    }

    Time &operator ++()
    {
      *this = Time(t_sec+1);
      return *this;
    }

    const Time operator ++(int)
    {
      Time t = *this;
      ++*this;
      return t;
    }
};

int main(void)
{
  Time t(1, 1, 1);
  t.OutTime();

  Time t2 = ++++t;
  t2.OutTime();
  
  t2 = t++;
  t2.OutTime();
  return 0;
}
