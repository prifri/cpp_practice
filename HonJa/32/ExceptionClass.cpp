#include <iostream>
#include "../include/comm.h"

class MyClass{
 private:
 public:
  class Exception{
   public:
    enum class E_Error{
      OUT_OF_MEMORY,
      RANGE_OVER,
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
          puts("Mem");
          break;
        case E_Error::RANGE_OVER:
          puts("Range");
          break;
        case E_Error::HARD_FULL:
          puts("hard");
          break;
      }
    }
  };


  void calc(void)
  {
    try {
      if (true)
        throw Exception(Exception::E_Error::RANGE_OVER);
    }catch (Exception &e){
      e.ReportError();
    }
  }

  void calc2(void)
  {
    try {
      if (true)
        throw Exception(Exception::E_Error::OUT_OF_MEMORY);
    }catch (Exception &e){
      e.ReportError();
    }
  }
};

int main(void)
{
  MyClass M;
  M.calc();

  try {
    M.calc2();
  }catch(MyClass::Exception &e){
    e.ReportError();
  }

  return 0;
}
