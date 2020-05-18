#include <iostream>
#include "../include/comm.h"
#include <cstring>

using namespace std;

class Human
{
  protected:
    char Name[16];
  public:
    Human(const char *arg_Name)
    {
      strncpy(Name, arg_Name, 15);
      Name[15] = '\0';
    }

    void Intro(void)
    {
      printf("name : %s\n", Name);
    }

    void Think(void)
    {
      puts("Human Think\n");
    }
};

class Student : public Human{
  private:
    int StNum;
  public:
    Student(const char *arg_Name, int arg_StNum) : Human(arg_Name), StNum(arg_StNum)
  {
  }

    void Intro(void)
    {
      Human::Intro();
      printf(", Num : %d\n", StNum);
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
  Human H("KSR");
  Student S("LHS", 1234567);
  Human *pH = &H;
  Student *pS = &S;

  cout << __LINE__ << endl;
  pH->Intro();
  cout << __LINE__ << endl;
  pH = &S;
  pH->Intro();
  cout << __LINE__ << endl;

  pS = (Student *)&H;
  pS->Intro();
  return 0;
}
