#include <iostream>
#include "../include/comm.h"

using namespace std;

int main(void)
{
  int i;

  try {
    printf("1~100 in i. ");
    cin >> i;
    if (cin.fail()){
      cin.clear();
    }

    if (i < 1 || i > 100){
      throw i;
    }

    printf("in = %d\n", i);
  }catch (int i){
    printf("%d 1~100 nono. ok?\n", i);
  }
  return 0;
}
