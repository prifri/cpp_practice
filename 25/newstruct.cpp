#include <iostream>
#include <cstring>
using namespace std;

struct tag_friend {
  char name[10];
  int age;
  double height;
};

int main()
{
#if 0 //is possible
  struct tag_friend *pf = new struct tag_friend;
#else
  tag_friend *pf = new tag_friend;
#endif

  if (pf == NULL){
    cout << "pf alloc error"<< endl;
    return 0;
  }
  strcpy(pf->name, "abc");
  pf->age = 10;
  pf->height = 123.4;

  printf("%s\n", pf->name);
  cout << "name : " << pf->name << ", age : " << pf->age
    << ", height : " << pf->height << endl;

  delete pf;
  return 0;
}
