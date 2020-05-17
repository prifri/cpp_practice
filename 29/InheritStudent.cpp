#include <iostream>
#include "../include/comm.h"
#include <cstring>

using namespace std;

class Human{
  protected:
    char Name[16];
  public:
    Human(const char *arg_Name)
    {
      strncpy(Name, arg_Name, 15);
      Name[15] = '\0';
    }
    void intro(void)
    {
      printf("name : %s\n", Name);
    }
    void Think(void)
    {
      cout << "abcd" << endl;
    }
};

class Student : public Human{
  private:
    int StNum;
  public:
    Student(const char *arg_Name, int arg_StNum) : Human(arg_Name), StNum(arg_StNum)
  {
  }

    void intro(void)
    {
      Human :: intro();
      printf(", num : %d", StNum);
    }

    void Think(void)
    {
      puts("Student Think");
    }

    void Study(void)
    {
      puts("Student Study");
    }
};

int main(void)
{
  Student K("KSH", 9506299);
  K.intro();
  puts("");
  K.Think();
  K.Study();
  return 0;
}
