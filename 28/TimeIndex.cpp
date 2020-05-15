#include <iostream>
#include "../include/comm.h"

using namespace std;

class Time{
  private:
    int hour, min, sec, t_sec;

    //const int &op_arr(int idx);
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

    const int& operator [] (int idx) const
    {
      switch(idx){
        case 0:
          return hour;
        case 1:
          return min;
        default:
          return sec;
      }
    }

    int& operator [] (int idx)
    {
      switch(idx){
        case 0:
          return hour;
        case 1:
          return min;
        default:
          return sec;
      }
    }
};

#if 0
const int& Time::op_arr(int idx)
{
}
#endif
int main(void)
{
  Time A(1, 1, 1);

  printf("%d %d %d\n", A[0], A[1], A[2]);
}
