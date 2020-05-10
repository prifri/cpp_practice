#include <iostream>
using namespace std;

#define ARR_SIZE  5
int main()
{
  int *ar = new int[ARR_SIZE];

  if (ar == NULL){
    cout << "ar alloc error" << endl;
    return 0;
  }

  for (int i=ARR_SIZE-1 ; i>=0 ; i--)
    ar[i] = i;

  for (int i=ARR_SIZE-1 ; i>=0 ; i--)
    cout << i << ' ';
  cout << endl;

  delete [] ar;
  return 0;
}

