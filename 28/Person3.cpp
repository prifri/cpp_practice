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

    person(const person &tmp)
    {
      name = new char[strlen(tmp.name)+1];
      strcpy(name, tmp.name);
      age = tmp.age;
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

    person &operator = (const person &p)
    {
      if (this != &p){
        delete [] p.name;
        name = new char[strlen(p.name)+1];
        strcpy(name, p.name);
        age = p.age;
      }

      return *this;
    }
};

int main(void)
{
  person boy("abcd", 12);
  person girl;
  girl = boy;
  boy.out();
  girl.out();
  return 0;
}
