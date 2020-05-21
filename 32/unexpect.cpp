#include <iostream>
#include "../include/comm.h"

using namespace std;

void myunext(void)
{
  puts("fault");
  exit(-2);
}

// 17부턴 지원안해
void calc() throw(int)
{
  throw "string";
}

int main(void)
{
  set_unexpected(myunext);
  try {
    calc();
  }catch(int) {
    puts("int except");
  }
  puts("ended");
  return 0;
}
