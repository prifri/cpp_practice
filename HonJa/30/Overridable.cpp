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
    unsigned size;
    const unsigned growby;
#define MAX_SIZE   15
    const unsigned max_size;

    eletype *arr;
  protected:
    unsigned cnt;
  public:
    DArray(unsigned a_size = 5, unsigned a_growby = 5);
    ~DArray(void);
    DArray(const DArray &tmp);

    int Insert(unsigned idx, eletype value);
    int Append(eletype value);
    int Delete(unsigned idx);
    virtual void Dump(const char *str) const ;
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

class MyDArray : public DArray {
  public:
    MyDArray(unsigned a_size=100, unsigned a_growby=10) : DArray(a_size, a_growby)
  {
  }
    void Dump(const char *sMark) const;
};

void MyDArray :: Dump(const char *sMark) const
{
  printf("%16s : cnt %d\n", sMark, cnt);
}

int main(void)
{
  MyDArray ar;
  DArray *p = &ar;
  int i;

  for (i=1; i<=13 ; i++){
    p->Append(i);
  }

  p->Dump("13 cnt add");
  p->Insert(3, 10);
  p->Dump("10 Insert");
  return 0;
}
