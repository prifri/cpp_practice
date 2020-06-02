#include <iostream>
#include "../include/comm.h"

using namespace std;

class simple{
  private:
    int value;
  public:
    simple(int arg_value) : value(arg_value)
    {
    }

    void out_value(void)
    {
      printf("value = %d\n", this->value);
      this->value++;
    }

    simple *find_big(simple *other)
    {
      if (other->value > value)
        return other;
      return this;
    }
};

int main(void)
{
  simple a(1);
  simple b(10);

  a.out_value();
  a.out_value();

  a.find_big(&b)->out_value();
  return 0;
}
