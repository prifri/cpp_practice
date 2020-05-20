#include <iostream>
#include "../include/comm.h"

using namespace std;


class Exception{
 public:
  enum class E_Error{
    OUT_OF_MEMORY,
    OVER_RANGE,
    HARD_FULL
  };
 private:
  E_Error ErrorCode;

 public:

  Exception(E_Error ae) : ErrorCode(ae)
  {
  }

  E_Error GetErrorCode(void)
  {
    return ErrorCode;
  }

  void ReportError(void)
  {
    switch (ErrorCode){
      case E_Error::OUT_OF_MEMORY:
        puts("mem");
        break;
      case E_Error::OVER_RANGE:
        puts("range");
        break;
      case E_Error::HARD_FULL:
        puts("hard");
        break;
    }
  }
};

void calc(void)
{
  int n = 1;
  if (n)
    throw Exception(Exception::E_Error::OUT_OF_MEMORY);
}

int main(void)
{
  try {
    calc();
    puts("abcd");
  } catch(Exception &e){
    printf("error = %d => ", static_cast<int>(e.GetErrorCode()));
    e.ReportError();
    printf("%d\n", static_cast<int>(Exception::E_Error::HARD_FULL));
  }
}
