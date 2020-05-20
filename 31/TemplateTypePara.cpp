#include <iostream>
#include "../include/comm.h"
#include "TStack.h"

using namespace std;

void DumpStack(TStack<int> &S)
{
  for (int i=S.GetTop() ; i>=0 ; i--){
    cout << i << " = " << S.GetValue(i) << endl;
  }
}

int main(void)
{
  TStack<int> iS(10);

  iS.Push(1);
  iS.Push(2);
  iS.Push(3);
  iS.Push(4);
  iS.Push(5);
  DumpStack(iS);
  return 0;
}
