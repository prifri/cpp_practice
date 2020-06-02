#include <iostream>
#include "../include/comm.h"

using namespace std;

class Date{
  protected:
    int year, month, day;
  public:
    Date(int y, int m, int d) : year(y), month(m), day(d)
  {
  }
    void OutDate(void)
    {
      printf("%d/%d/%d", year, month, day);
    }
};

class Time{
  protected:
    int hour, min, sec;
  public:
    Time(int h, int m, int s) : hour(h), min(m), sec(s)
  {
  }

    void OutTime(void)
    {
      printf("%d:%d:%d", hour, min, sec);
    }
};

class Now : public Date, public Time {
  private:
    bool bEngMessage;
    int milisec;
  public:
    Now(int y, int m, int d, int h, int min, int s, int ms, bool b=false) : Date(y, m, d), Time(h, min, s), bEngMessage(b), milisec(ms)
  {
  }

    void OutNow()
    {
      printf(bEngMessage ? "Now is": "지금은 ");
      OutDate();
      putch(' ');
      OutTime();
      printf(".%d", milisec);
      puts(bEngMessage ? ".":"이다");
    }
};

int main (void)
{
  Now N(2005, 1, 2, 12, 30, 58, 99);
  N.OutNow();
  return 0;
}
