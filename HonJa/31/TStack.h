#ifndef __tsSTACK_H__
#define __tsSTACK_H__

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

template <typename T>
class TStack{
 private:
  T *stack;
  int size;
  int top;

 public:
  TStack(int aSize) : size(aSize)
  {
    stack = (T *)malloc(size*sizeof(T));
    top = -1;
  }

  virtual ~TStack(void)
  {
    free(stack);
  }

  virtual bool Push(T data)
  {
    if (top < size-1){
      stack[++top] = data;
      return true;
    }
    else {
      return false;
    }
  }

  virtual T Pop(bool *result)
  {
    if (top >= 0){
      if (result)
        *result = true;
      return stack[top--];
    }
    else {
      if (result)
        *result = false;
      return stack[0];
    }
  }
  virtual int GetTop(void)
  {
    return top;
  }

  virtual T GetValue(int n)
  {
    return stack[n];
  }
  void DbgShowStack(void)
  {
#ifdef DEBUG_ON
    for (int i=0 ; i<=top ; i++){
      cout << stack[i] << " ";
    }
#endif
  }
};

#endif
