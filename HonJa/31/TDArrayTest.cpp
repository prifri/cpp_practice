#include <iostream>
#include "../include/comm.h"
#include "TDArray.h"
using namespace std;


int main(void)
{
  TDArray<int> ari;
  TDArray<double> ard;
  
  for (int i=0 ; i<=5 ;i++)
    ari.Append(i);

  ari.Dump("5Dogs Add");

  for (int i=0; i<=3 ;i++)
    ard.Append((double)i*1.23);
  ard.Dump("3Dogs Add");
  return 0;
}
