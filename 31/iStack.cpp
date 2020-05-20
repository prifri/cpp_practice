#include <iostream>
#include "../include/comm.h"

using namespace std;

class iStack{
 private:
  int *stack;
  int size;
  int top;

 public:
  iStack(int aSize) : size(aSize)
  {
    stack = (int *)malloc(size*sizeof(int));
    top = -1;
  }

  virtual ~iStack(void)
  {
    free(stack);
  }

  virtual bool Push(int data)
  {
    if (top < size-1){
      stack[++top] = data;
      return true;
    }
    else {
      return false;
    }
  }

  virtual int Pop(void)
  {
    if (top >= 0)
      return stack[top--];
    return -1;
  }
};

int main(void)
{
  iStack iS(256);
  iS.Push(7);
  iS.Push(0);
  iS.Push(6);
  iS.Push(2);
  iS.Push(9);
  printf("%d\n", iS.Pop());
  printf("%d\n", iS.Pop());
  printf("%d\n", iS.Pop());
  printf("%d\n", iS.Pop());
  printf("%d\n", iS.Pop());
  printf("%d\n", iS.Pop());
  printf("%d\n", iS.Pop());
  printf("%d\n", iS.Pop());
  return 0;
}
