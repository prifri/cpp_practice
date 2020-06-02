#include <iostream>
#include "../include/comm.h"

using namespace std;

class exchange{
  private:
    static double rate;
  public:
    static double get_rate(void)
    {
      return rate;
    }

    static void set_rate(double arg_rate)
    {
      rate = arg_rate;
    }

    double dollar2won(double d)
    {
      return d*rate;
    }

    double won2dollar(double w)
    {
      return w/rate;
    }
};

double exchange :: rate;

int main(void)
{
  exchange :: set_rate(1200);
  exchange a, b;

  printf("a dollar is %.0f won\n", a.dollar2won(1));
  exchange :: set_rate(1150);

  printf("a dollar is %.0f won\n", b.dollar2won(1));
  return 0;
}
