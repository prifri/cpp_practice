#include <iostream>
#include "../include/comm.h"

using namespace std;

class Time{
  private:
    unsigned hour, min, sec;
    uint64_t t_sec;
  public:
    Time(unsigned ah, unsigned am, unsigned as) :
      hour(ah), min(am), sec(as)
    {
      t_sec = hour*60*60 + min*60 + sec;
    }

    Time(uint64_t ats) : t_sec(ats)
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

    operator uint64_t()
    {
      return t_sec;
    }

    //+
    const Time operator +(const Time &t) const
    {
      return Time(t.t_sec + t_sec);
    }

    const Time operator +(uint64_t &s) const
    {
      return Time(t_sec + s);
    }

    //==
    const bool operator == (const Time &t) const
    {
      return t_sec == t.t_sec;
    }

    const bool operator == (uint64_t s) const
    {
      return t_sec == s;
    }

    //!=
    const bool operator !=(const Time &t) const
    {
      return t_sec != t.t_sec;
    }
    const bool operator != (uint64_t s) const
    {
      return t_sec != s;
    }

    //>=
    const bool operator >=(const Time &t) const
    {
      return t_sec >= t.t_sec;
    }
    const bool operator >= (uint64_t s) const
    {
      return t_sec >= s;
    }
};
int main(void)
{
  Time t1(4000);
  Time t2(5000);

  if (t1 >= (uint64_t)3000)
    printf("t1 >= 3000\n");
  else
    printf("t1 < 3000\n");

  if (t2 == (uint64_t)5000)
    printf("t2 == 5000\n");
  else
    printf("t2 != 5000\n");

  if (t1+t2 != (uint64_t)2000)
    printf("t1+t2 != 2000\n");
  else
    printf("t1+t2 == 2000\n");
  return 0;
}
