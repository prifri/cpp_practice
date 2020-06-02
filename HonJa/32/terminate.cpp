#include <iostream>
#include "../include/comm.h"

using namespace std;

void myterm(void)
{
  puts("abcd");
  exit(-1);
}

int main(void)
{
  set_terminate(myterm);
  try{
    throw 'a';
  }catch(char *m){
    printf("hello\n");
  }catch(int){
    printf("int hello!\n");
  }catch(long long int){
    printf("int hello!\n");
  }
#if 0
  catch(...){
    printf("omg\n");
  }
#endif
  printf("end\n");
  return 0;
}
