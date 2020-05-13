#include <iostream>
#include "../include/comm.h"

using namespace std;

class Time{
  private:
    int hour, min, sec;
  public:
    Time(void)
    {
    }

    Time(int abssec)
    {
      hour = abssec/3600;
      min = (abssec/60)%60;
      sec = abssec%60;
    }

    Time(int h, int m, int s) : hour(h), min(m), sec(s)
  {
  }
    int IntToTime(void)
    {
      return hour*3600 + min*60 + sec;
    }

    void out_Time(void)
    {
      printf("set Time %02d:%02d:%02d\n", hour, min, sec);
    }
};

int main(void)
{
  Time a(10,20,30);
  int t = a.IntToTime();

  a.out_Time();
  printf("t = %d\n", t);
  return 0;
}
