#include <iostream>
#include <cstring>
#include "../include/comm.h"

using namespace std;

class Parent{
 protected:
  const char *Name;
 public:
  virtual void PrintMe(void)
  {
    Name = "Parent";
    printf("Parent\n");
  }
  virtual const char *GetName(void)
  {
    return Name;
  }
};

class Child : public Parent{
 private:
  int num;
 public:
  Child(int anum=1234) : num(anum)
  {
    Name = "Child";
  }
  virtual void PrintMe()
  {
    printf("Child\n");
  }
  void PrintNum()
  {
    printf("child = %d\n", num);
  }
};

void func(Parent &p)
{
  p.PrintMe();
  if (strcmp(p.GetName(), "Child") == 0)
    ((Child &)p).PrintNum();
  else
    puts("not have num");
}

int main(void)
{
  Parent p;
  Child c(5);

  func(c);
  func(p);
  return 0;
}
