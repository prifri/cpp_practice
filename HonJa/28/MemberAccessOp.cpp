#include <iostream>
#include <cstring>

using namespace std;

struct Author {
  char Name[32];
  char Tel[24];
  int Age;
};

class Book
{
  private:
    char Title[32];
    Author Writer;
  public:
    Book(const char *arg_Title, const char *arg_Name, int arg_age)
    {
      strncpy(Title, arg_Title, 31);
      strncpy(Writer.Name, arg_Name, 23);
      Writer.Age = arg_age;
    }

    Author *operator->()
    {
      return &Writer;
    }

    const char *GetTitle(void)
    {
      return Title;
    }
};

int main(void)
{
  Book Hyc("혼자 연구하는 C/C++", "김상형", 40);
  printf("title : %s, writer : %s age : %d\n",
      Hyc.GetTitle(), Hyc->Name, Hyc->Age);
  return 0;
}

