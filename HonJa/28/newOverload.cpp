#include <iostream>
#include "../include/comm.h"

using namespace std;

void *operator new(size_t t) 
{
  return malloc(t);
}

void operator delete(void *p)
{
  printf("hi2\n");
  free(p);
}

void operator delete(void *p, std::size_t) 
{
  printf("hi\n");
  free(p);
}

int main(void)
{
  int *pi = new int;
  *pi = 1234;
  printf("%d\n", *pi);
  delete pi;
  return 0;
}
