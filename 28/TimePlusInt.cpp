#include <iostream>
#include "../include/comm.h"

using namespace std;

class Time{
  private:
    unsigned hour, min, sec, t_sec;
    uint64_t tt;
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
};

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
  Time t4 = t3 + 3;
  Time t5 = 3 + t4;
  Time t6 = t1 -10 - t2 + 3 + t4;
  t1.OutTime();
  t2.OutTime();
  t3.OutTime();
  t4.OutTime();
  t5.OutTime();
  t6.OutTime();
  return 0;
}
