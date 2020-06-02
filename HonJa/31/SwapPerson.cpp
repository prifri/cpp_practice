#include <iostream>
#include "../include/comm.h"
#include <cstring>

using namespace std;

template <typename T>

void swap_my(T &a, T &b)
{
  T t;
  t = a;
  a = b;
  b = t;
}

class Person{
  private:
    char *name;
    int len;
    int age;
    void init_person(const char *arg_name, int arg_age)
    {
      len = strlen(arg_name);
      name = new char[len+1];
      strcpy(name, arg_name);
      age = arg_age;
    }
  public:
    Person(void)
    {
      name = new char[1];
      name[0] = '\0';
      age = 0;
      len = 0;
    }

    Person(const char *arg_name, int arg_age)
    {
      init_person(arg_name, arg_age);
    }

    Person(const Person &Other)
    {
      init_person(Other.name, Other.age);
    }

    Person &operator =(const Person &Other)
    {
      if (this != &Other){
        delete [] name;
        init_person(Other.name, Other.age);
      }
      return *this;
    }

    virtual ~Person(void)
    {
      delete [] name;
    }

    virtual void OutPerson(void)
    {
      printf("Nmae : %s age : %d\n", name, age);
    }
};

int main(void)
{
  Person A("AAA", 10);
  Person B("BBB", 20);

  A.OutPerson();
  B.OutPerson();

  swap_my(A, B);

  A.OutPerson();
  B.OutPerson();
  return 0;
}
