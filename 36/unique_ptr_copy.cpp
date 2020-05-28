#include <iostream>
#include "../include/comm.h"
#include <memory>

//https://modoocode.com/229
using namespace std;

class A {
  int *data;
  char ch;

 public:
  A(char ach = 'A') : ch(ach)
  {
    data = new int[100];
    std::cout << "자원을 획득함!" << ch << std::endl;
  }

  void some(void)
  {
    std::cout << "일반 포인터와 동일하게 사용가능!" << ch << std::endl;
  }

  ~A(void)
  {
    std::cout << "소멸자 호출!" << ch << std::endl;
    delete[] data;
  }

  void change(char ach)
  {
    ch = ach;
  }
};

void thrower(void)
{
  throw 1;
}

void do_something2(A *ptr)
{
  cout << "2 start" << endl;
  ptr->some();
}

void do_something(void)
{
#if 0 //11
  unique_ptr<A> pa(new A);
#else //14
  auto pa = make_unique<A>('Z');
#endif

  pa->some();
  unique_ptr<A> pb = move(pa);
  
  cout << "copy(move) done" << endl;
  //pa->some(); //seg fault
  
  pb->some();

  pb->change('b');
  pb->some();

  do_something2(pb.get());

  cout << "2 end" << endl;
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
