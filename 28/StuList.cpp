#include <iostream>
#include "../include/comm.h"
#include <cstring>

using namespace std;

class StuList{
  private:
    struct Student{
      char name[10];
      int num;
    };
    struct Student S[30];

    void SetStudent(const char *name, int num, unsigned idx)
    {
      if (strlen(name) < 10 && idx < 30){
        strcpy(S[idx].name, name);
        S[idx].num = num;
      }
    }
  public:
    StuList(void)
    {
      SetStudent("AAA", 3, 0);
      SetStudent("bbb", 4, 1);
      SetStudent("CCC", 5, 2);
      SetStudent("Adc", 6, 3);
      SetStudent("Aec", 7, 4);
      SetStudent("Afc", 8, 5);
      SetStudent("Agc", 1, 6);
      SetStudent("Ahc", 3, 7);
      SetStudent("---", 0, 8);
    }

    const int operator [](const char *s) const
    {
      for (int i=7 ; i>=0 ; i--){
        if (strcmp(s, S[i].name) == 0)
          return S[i].num;
      }
      return -1;
    }
};

int main(void)
{
  StuList SL;

  printf("CCC student number is %d\n", SL["CCC"]);
  return 0;
}
