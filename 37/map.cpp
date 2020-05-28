#include <iostream>
#include "../include/comm.h"
#include <map>

using namespace std;

struct SProduct{
  string Name;
  int price;
};

SProduct arPro[] = {
  {"a", 1},
  {"b", 2},
  {"c", 3},
  {"d", 4},
  {"e", 5},
  {"f", 6},
};

int main(void)
{
  map<string, int> mPro;
  map<string, int> ::iterator it;

  int i;
  string name;

  for (i=0; i<(int)(sizeof(arPro)/sizeof(arPro[0])) ; i++)
    mPro[arPro[i].Name] = arPro[i].price;

  while (1){
    cout << "int name(end) : " << endl;
    cin >> name;

    if (name == "end")
      break;

    it = mPro.find(name);

    if (it == mPro.end())
      cout << "none." << endl;
    else
      cout << name << " : " << it->second << "." << endl;
  }
  return 0;
}
