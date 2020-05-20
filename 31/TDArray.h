#ifndef __tdaRRAY_H__
#define __tdaRRAY_H__
#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
class TDArray{
  private:
    unsigned size;
    const unsigned growby;
#define MAX_SIZE   15
    const unsigned max_size;

    T *arr;
  protected:
    unsigned cnt;
  public:
    TDArray(unsigned a_size = 5, unsigned a_growby = 5);
    ~TDArray(void);
    TDArray(const TDArray &tmp);

    int Insert(unsigned idx, T value);
    int Append(T value);
    int Delete(unsigned idx);
    virtual void Dump(const char *str) const ;
};

template <typename T>
TDArray<T> :: TDArray(unsigned a_size, unsigned a_growby) :
  size(a_size), growby(a_growby), max_size(MAX_SIZE)
{
  arr = (T *)malloc(sizeof(T)*a_size);
  if (arr == NULL){
    //need error
  }

  cnt = 0;
}

template <typename T>
TDArray<T> :: ~TDArray(void)
{
  free(arr);
}

template <typename T>
TDArray<T> :: TDArray(const TDArray &tmp) :
  growby(tmp.growby), max_size(tmp.max_size)
{
#if 1
  arr = (T *)malloc(sizeof(T)*tmp.size);
  memcpy(arr, tmp.arr, sizeof(T)*tmp.size);
  size = tmp.size;
  cnt = tmp.cnt;
#endif
}

template <typename T>
int TDArray<T> :: Insert(unsigned idx, T value)
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
    arr = (T *)realloc(arr, extend_size*sizeof(T));
    size = extend_size;
  }
  else {
    printf("index is too large(%u). max size is : %u\n", idx, max_size);
    return -1;
  }

  memmove(arr+idx+1, arr+idx, (cnt - idx)*sizeof(T));
  arr[idx] = value;
  cnt = after_cnt;
  return 0;
}

template <typename T>
int TDArray<T> :: Append(T value)
{
  return TDArray :: Insert(cnt, value);
}

template <typename T>
int TDArray<T> :: Delete(unsigned idx)
{
  if (idx < cnt ){
    memmove(arr+idx, arr+idx+1, (cnt - idx - 1)*sizeof(T));
    cnt--;
    return 0;
  }
  printf("curr cnt is %u. index is over (%u)\n", cnt, idx);
  return -1;
}

template <typename T>
void TDArray<T> :: Dump(const char *str) const
{
  cout << str << " >> " << "size : " << size << " cnt : " << cnt << " : ";
  for (unsigned i=0 ; i<cnt ; i++){
    cout << arr[i] << " ";
  }
  cout << endl;
}
#endif
