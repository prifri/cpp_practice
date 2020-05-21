#include <iostream>
#include "../include/comm.h"

class Exnegative{
 protected:
  int Number;

 public:
  Exnegative(int n) : Number(n)
  {
  }

  virtual void PrintError(void)
  {
    printf("%d is minus. invalid\n", Number);
  }
};

class ExTooBig : public Exnegative
{
 public:
  ExTooBig(int n) : Exnegative(n)
  {
  }

  virtual void PrintError(void)
  {
    printf("%d is too large. lt 100.\n", Number);
  }
};

class ExOdd : public Exnegative
{
 public:
  ExOdd(int n) : Exnegative(n)
  {
  }

  virtual void PrintError(void)
  {
    printf("%d is odd. even\n", Number);
  }
};

int main(void)
{

  while (1){
    int n;
    try {
      printf("int (end is 0) : ");
#if 0
      scanf("%d", &n);
#else
      std::cin >> n;
      if (std::cin.fail()){
        std::cin.clear();
        printf("invalid input value\n");
        continue;
      }
#endif
      fflush(stdin);
      if (n == 0)
        break;
      if (n < 0)
        throw Exnegative(n);
      else if (n > 100)
        throw ExTooBig(n);
      if (n & 0x1)
        throw ExOdd(n);

      printf("recv num %d\n", n);
    }catch (Exnegative &e){
      e.PrintError();
    }
  }
  return 0;
}
