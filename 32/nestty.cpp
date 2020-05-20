#include <iostream>
#include "../include/comm.h"
#include <cstring>

int main(void)
{
  int num;
  int age;
  char name[128];

  try {
    printf("num : " );
    std::cin >> num;
    fflush(stdin);

    if (num <= 0)
      throw num;

    try {
      printf("name : " );
      std::cin >> name;
      if (strlen(name) < 4 )
        throw "name is too short";
      printf("age : " );
      std::cin >> age;
      if (age <= 0)
        throw age;
      printf("%d %s %d\n", num, name, age);
    }catch (const char *msg){
      puts(msg);
    } catch (int){
        throw;
    }
  }catch(int n){
    printf("%d is minus. invalid.\n", n);
  }
  return 0;
}
