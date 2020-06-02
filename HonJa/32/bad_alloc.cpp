#include <iostream>
#include "../include/comm.h"

using namespace std;

#define MAX 1024

struct oops : std::bad_alloc{
  const char *what(void) const noexcept {return "Ooops!\n";}
};

int main(void)
{
  int *pi[MAX] = {NULL,};
  int i;

  try {
    try {
      for (i=MAX-1; i>=0; i--){
        pi[i] = new int[1024*1024];

        if (pi[i]){
          printf("%d success.\n", i);
        }
        else{
          // 실행안함
          printf("%d fail\n", i);
        }
      }

      for (i=MAX; i>=0 ;i--)
        delete [] pi[i];
    }catch (bad_alloc &b){
      cout << "error occured :" << b.what() << endl;
      for (++i; i <MAX ; i++){
        //  printf("%d delete.\n", i);
        delete [] pi[i];
      }
      throw oops();
    }
  }catch (bad_alloc &b){
    cout << "222 : " << b.what() << endl;
  }

  return 0;
}
