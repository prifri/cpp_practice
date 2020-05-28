#include <iostream>
#include "../include/comm.h"
#include <memory>

//https://modoocode.com/229
using namespace std;

class A {
  int *data;

 public:
  A(void)
  {
    data = new int[100];
    std::cout << "자원을 획득함!" << std::endl;
  }

  void some(void)
  {
    std::cout << "일반 포인터와 동일하게 사용가능!" << std::endl;
  }

  ~A(void)
  {
    std::cout << "소멸자 호출!" << std::endl;
    delete[] data;
  }
};

void thrower(void)
{
  throw 1;
}

void do_something(void)
{
  unique_ptr<A> pa(new A);
  pa->some();
}

int main(void)
{
  try {
    do_something();
  }catch (int i){
    cout << "exception" << endl;
  }
  return 0;
}
