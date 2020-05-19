#include <iostream>
#include "../include/comm.h"

using namespace std;

template <typename T, int N> class Array
{
private:
 T ar[N];
public:
 void SetAt(int n, T v)
 {
   if (n < N && n >= 0)
     ar[n] = v;
 }

 T GetAt(int n)
 {
   return (n < N && n >= 0) ? ar[n] : 0;
 }
};

/*
 * constexpr test..
 * if return typte is const.. than error
 */
constexpr int test(int a)
{
  if (a > 3)
    return 4;
  return 5;
}

int main(void)
{
#if 0 //error
  int size = 5;
  Array<int,size> ari;
#else
#if 1 //test constexpr
  Array<int,test(4)> ari;
#else
  Array<int,5> ari;
#endif
#endif
  ari.SetAt(1, 1234);
  ari.SetAt(1000, 5678);
  printf("%d\n", ari.GetAt(1));
  printf("%d\n", ari.GetAt(5));
  return 0;
}
