#include <iostream>
#include "../include/comm.h"

template <int N>
void func(void)
{
  int ar[N];

  for (int i=0 ; i<N ; i++){
    ar[i] = i;
  }
  printf("arr size + %d %d\n", N, ar[0]);
}

int main(void)
{
  func<5>();
  func<7>();
  return 0;
}
