#include <iostream>
#include <cstring>
#include "../include/comm.h"
using namespace std;

class person{
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

int main(void)
{
  person boy("abcd", 12);
  person girl;
  boy.out();
  girl.out();
  return 0;
}
