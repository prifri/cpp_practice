#include <iostream>
#include <cstring>
#include "../include/comm.h"
using namespace std;

class person{
  friend std::ostream &operator << (std::ostream &c, person &p);
  private:
    char *name;
    int age;
  public:
    person(void)
    {
      name = new char[3];
      strcpy(name, "ab");
      age = 10;
    }

    person(const char *arg_name, int arg_age)
    {
      name = new char[strlen(arg_name) + 1];
      strcpy(name, arg_name);
      age = arg_age;
    }

    ~person(void)
    {
      cout << "deinit.." << name << endl;
      delete [] name;
    }

    void out(void)
    {
      cout << "name : " << name << ", age : " << age << endl;
    }
};

std::ostream &operator << (std::ostream &c, person &p)
{
  c << "name : " << p.name << ", age : " << p.age ;
  return c;
}

std::ostream &operator << (std::ostream &c, person *p)
{
  c << *p;
  return c;
}

int main(void)
{
  person boy("abcd", 12);
  
  cout << boy <<endl;
  
  person *p = new person;

  cout << p <<endl;

  delete p;
  return 0;
}
