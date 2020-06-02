#include <iostream>
#include <cstring>
#include <typeinfo>
#include "../include/comm.h"

class Parent{
 public:
  virtual void PrintMe(void)
  {
    printf("Parent hi\n");
  }
};

class Child : public Parent{
 private:
  int num;
 public:
  Child(int an) : num(an)
  {
  }

  virtual void PrintMe(void)
  {
    printf("Child hi\n");
  }

  void PrintNum(void)
  {
    printf("num : %d\n", num);
  }
};

void func(Parent &p)
{
  p.PrintMe();

  try{
    Child &c = dynamic_cast<Child &>(p);
    c.PrintNum();
  }catch(std::bad_cast &b){
    std::cout << "not have num : " << b.what() << std::endl;
  }

}

int main(void)
{
  Child c(5);
  Parent p;

  func(c);
  func(p);
  return 0;
}
