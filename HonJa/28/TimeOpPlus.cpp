#include <iostream>
#include "../include/comm.h"

using namespace std;

class Time{
  friend const Time operator +(const Time &T1, const Time &T2);
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
};

const Time operator +(const Time &t1, const Time &t2)
{
  return Time(t1.t_sec + t2.t_sec);
}

int main(void)
{
#if 0
  Time t1(4000);
  Time t2(5000);
#else
  Time t1(1,2,3);
  Time t2(4,5,6);
#endif
  Time t3 = t1 + t2;
  t1.OutTime();
  t2.OutTime();
  t3.OutTime();
  return 0;
}
