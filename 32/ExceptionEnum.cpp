#include <iostream>
#include "../include/comm.h"

/*
 * Dynamic exception specifications are deprecated since C++11, 
 * and are illegal since C++17, so you might want to get rid of them 
 * and upgrade third-party libraries you are using as soon as possible.
 * 안된다는 뜻.. 이 예제는 이제 사용못한다.
 * 어짜피 다음 예제처럼 class로 만들어서 쓰는게 실용적이겟지
 */
using namespace std;

enum E_Error{
  OUT_OF_MEMORY,
  OVER_RANGE,
  HARD_FULL
};

void calc(void) throw(E_Error)
{
  int n = 1;
  if (n)
    throw OUT_OF_MEMORY;
  printf("hi\n");
}

int main(void)
{
  try {
    calc();
    puts("compelte");
  }catch (E_Error e){
    switch (e){
      case OUT_OF_MEMORY:
        puts("mem");
        break;
      case OVER_RANGE:
        puts("range");
        break;
      case HARD_FULL:
        puts("hard");
        break;
    }
  }
  return 0;
}
