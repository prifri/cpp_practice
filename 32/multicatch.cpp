#include <iostream>
#include "../include/comm.h"

using namespace std;

int main(void)
{
  int a, b;

  try {
    printf("나누어질수 ");
    cin >> a;
    if (a < 0)
      throw a;
    printf("나누는수 ");
    cin >> b;
    if (b < 0)
      throw b;
    if (b == 0)
      throw "0 is invalid";
    printf("result %d\n", a/b);
  }catch(int a){
  }catch(const char *msg){
    puts(msg);
  }
  return 0;
}
