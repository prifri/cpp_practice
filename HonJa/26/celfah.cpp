#include <iostream>
#include "../include/comm.h"

using namespace std;

class fahrenheit;

class celsius {
  private:
  protected:
  public:
    double tem;
    celsius(void)
    {
    }

    celsius(double arg_tem) : tem(arg_tem)
    {
    }

    operator fahrenheit();
    void out_tem(void)
    {
      printf("cel temp : %f\n", tem);
    }
};

class fahrenheit {
  private:
  protected:
  public:
    double tem;
    fahrenheit(void)
    {
    }

    fahrenheit(double arg_tem) : tem(arg_tem)
    {
    }

    operator celsius();
    void out_tem(void)
    {
      printf("fah temp : %f\n", tem);
    }
};

celsius :: operator fahrenheit()
{
  fahrenheit f;
  f.tem = tem*1.8+32;
  return f;
}

fahrenheit :: operator celsius()
{
  celsius c;
  c.tem = (tem-32)/1.8;
  return c;
}

int main(void)
{
  celsius c(100);
  fahrenheit f = c;
  c.out_tem();
  f.out_tem();

  fahrenheit f2(100);
  celsius c2 = f2;
  c2.out_tem();
  f2.out_tem();
}
