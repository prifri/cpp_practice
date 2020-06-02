#include <iostream>
#include "../include/comm.h"
#include <cmath>

using namespace std;

int main(void)
{
  int x, y, r;

  try {
    printf("x : ");
    cin >> x;
    if (x < 0)
      throw x;

    printf("y : ");
    cin >> y;
    if (y < 0)
      throw y;

    printf("r : ");
    cin >> r;
    if (r < 0)
      throw r;
  }catch (int a){
    printf("%d is minus. it is invalid\n", a);
    exit(-1);
  }

  clrscr();
  gotoxy(x, y);
  printf("%d squre is %.4f\n", r, sqrt(r));
  return 0;
}
