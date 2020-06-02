#include <iostream>
#include <cstring>
#include "../include/comm.h"

using namespace std;

/*
 * init(uint size, growby)
 * deinit()
 * insert(int idx, value)
 * appand(value)
 * delete(int idx)
 * dump(string) : string => size = A, cnt = B : m1, m2 ~ mB
 */

typedef int eletype;

class DArray{
  private:
    const unsigned growby;
#define MAX_SIZE   15
    const unsigned max_size;

    unsigned size;
    eletype *arr;
    unsigned cnt;
  public:
    DArray(unsigned a_size = 5, unsigned a_growby = 5);
    ~DArray(void);
    DArray(const DArray &tmp);

    int Insert(unsigned idx, eletype value);
    int Append(eletype value);
    int Delete(unsigned idx);
    void Dump(const char *str) const ;
};

DArray :: DArray(unsigned a_size, unsigned a_growby) :
  size(a_size), growby(a_growby), max_size(MAX_SIZE)
{
  arr = (eletype *)malloc(sizeof(eletype)*a_size);
  if (arr == NULL){
    //need error
  }

  cnt = 0;
}

DArray :: ~DArray(void)
{
  free(arr);
}

DArray :: DArray(const DArray &tmp) :
  growby(tmp.growby), max_size(tmp.max_size)
{
#if 1
  arr = (eletype *)malloc(sizeof(eletype)*tmp.size);
  memcpy(arr, tmp.arr, sizeof(eletype)*tmp.size);
  size = tmp.size;
  cnt = tmp.cnt;
#endif
}

int DArray :: Insert(unsigned idx, eletype value)
{
  unsigned after_cnt = cnt+1;
  if (idx > after_cnt){
    printf("index is too large(%u), current count is %u\n", idx, cnt);
    return -1;
  }
  else if (after_cnt <= size){
  }
  else if (after_cnt <= max_size){
    unsigned extend_size = min(size+growby, max_size);
    arr = (eletype *)realloc(arr, extend_size*sizeof(eletype));
    size = extend_size;
  }
  else {
    printf("index is too large(%u). max size is : %u\n", idx, max_size);
    return -1;
  }

  memmove(arr+idx+1, arr+idx, (cnt - idx)*sizeof(eletype));
  arr[idx] = value;
  cnt = after_cnt;
  return 0;
}

int DArray :: Append(eletype value)
{
  return DArray :: Insert(cnt, value);
}
int DArray :: Delete(unsigned idx)
{
  if (idx < cnt ){
    memmove(arr+idx, arr+idx+1, (cnt - idx - 1)*sizeof(eletype));
    cnt--;
    return 0;
  }
  printf("curr cnt is %u. index is over (%u)\n", cnt, idx);
  return -1;
}
void DArray :: Dump(const char *str) const
{
  cout << str << " >> " << "size : " << size << " cnt : " << cnt << " : ";
  for (unsigned i=0 ; i<cnt ; i++){
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main(void)
{
  DArray ar;
  int i;

  for (i=1; i<=13 ; i++){
    ar.Append(i);
    ar.Dump("13 cnt add");
  }

  ar.Insert(3, 10);
  ar.Dump("add 10 val");
  ar.Insert(3, 11);
  ar.Dump("add 11 val");
  ar.Insert(3, 12);
  ar.Dump("add 12 val");
  ar.Delete(7);
  ar.Dump("del 7 idx");

#if 0
  for (i=1; i<=15 ; i++){
    ar.Delete(0);
    ar.Dump("del 0 idx");
  }
#endif

  DArray ar2 = ar;
  ar2.Dump("copy ar2 obj");
  return 0;
}
