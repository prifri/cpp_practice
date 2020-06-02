#include <iostream>
#include "../include/comm.h"

using namespace std;

class Outer{
  private:
    class Inner{
      private:
        int memA;
      public:
        Inner(int a) : memA(a)
      {
      }
        int GetA(void)
        {
          return memA;
        }
    } obj;
  public:
    Outer(int a) : obj(a)
  {
  }
    void OutOuter(void)
    {
      printf("mem val = %d\n", obj.GetA());
    }
};

int main(void)
{
  Outer O(345);
  O.OutOuter();
  return 0;
}
