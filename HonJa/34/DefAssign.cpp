#include <iostream>
#include <cstring>
#include "../include/comm.h"
using namespace std;

class Person
{
  private:
    char *name;
    int age;
  public:
    Person(void)
    {
      name = new char[3];
      strcpy(name, "ab");
      age = 10;
      printf("init\n");
    }

    Person(const char *arg_name, int arg_age)
    {
      name = new char[strlen(arg_name) + 1];
      strcpy(name, arg_name);
      age = arg_age;
      printf("init\n");
    }

    Person(const Person &tmp)
    {
      name = new char[strlen(tmp.name)+1];
      strcpy(name, tmp.name);
      age = tmp.age;
      printf("init\n");
    }

    ~Person(void)
    {
      cout << "deinit.." << name << endl;
      delete [] name;
      printf("deinit\n");
    }

    void out(void)
    {
      cout << "name : " << name << ", age : " << age << endl;
    }

    Person &operator = (const Person &p)
    {
      if (this != &p){
        printf("deinit\n");
        printf("init\n");
        delete [] name;
        name = new char[strlen(p.name)+1];
        strcpy(name, p.name);
        age = p.age;
      }

      return *this;
    }
};

class Book
{
 private:
  char Title[32];
  Person Author;
 public:
  Book(void)
  {
    strcpy(Title, "None");
  }
  Book(const char *aname, int aAge, const char *aTitile) :
      Author(aname, aAge)
  {
    strncpy(Title, aTitile, 31);
    Title[31] = '\0';
  }
  void OutBook(void)
  {
    printf("Title : %s\n", Title);
    printf("Author info => ");
    Author.out();
  }
};

int main(void)
{
  Book Hyc("KSH", 99, "혼자 연구하는 C/C++");
  Hyc.OutBook();
  Book CPrg;
  CPrg = Hyc;
  CPrg.OutBook();
  return 0;
}
