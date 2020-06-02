#include <iostream>
#include "../include/comm.h"
#include <cstring>
using namespace std;

class person{
  private:
    char *name;
    int age;
  public:
    person(const char *arg_name, int arg_age)
    {
      name = (char *)malloc(strlen(arg_name)+1);
      strcpy(name, arg_name);
      age = arg_age;
    }
    ~person(void)
    {
      cout << "deinit call" << endl;
      free(name);
    }
    void outperson(void)
    {
      cout << "name : " << name << " age : " << age << endl;
    }

};

int main(void)
{
  person *per = new person("abcd", 12);
  per->outperson();
  delete per;
  return 0;
}
