#include <iostream>
#include "../include/comm.h"
#include <cstring>

using namespace std;

class ScoreManager
{
  private:
    int ar[3][5][10][4];
  public:
    ScoreManager(void)
    {
      memset(ar, 0, sizeof(ar));
    }

    int &operator ()(int Grade, int Class, int StNum,
        const char *Subj  __attribute__((unused)))
    {
      return ar[Grade][Class][StNum][0];
    }

    const int &operator ()(int Grade, int Class, int StNum,
        const char *Subj  __attribute__((unused))) const
    {
      return ar[Grade][Class][StNum][0];
    }
};

int main(void)
{
  ScoreManager SM;

  printf("%d\n", SM(1,2,3,"abc"));
  SM(1,2,3,"ab") = 99;
  printf("%d\n", SM(1,2,3,"abc"));
  return 0;
}
