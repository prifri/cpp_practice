#include <iostream>
#include "../include/comm.h"

using namespace std;

class Time{
  friend std::ostream &operator << (std::ostream &c, const Time &t);
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

};

std::ostream &operator << (std::ostream &c, const Time &t)
{
  c << t.hour << "hour" << t.min << "min" << t.sec << "sec";
  return c;
}

std::ostream &operator << (std::ostream &c, const Time *pt)
{
  c << *pt;
  return c;
}

int main(void)
{
  Time A(1, 1, 1);
  Time *p;

  p = new Time(2, 2, 2);
  cout << "curr time : " << A << " death." << endl;
  cout << "curr time : " << p << " death." << endl;
  delete p;
}
