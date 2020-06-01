#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

struct IsKim{
  bool operator()(string name) const
  {
    return (strncmp(name.c_str(), "김", 2) == 0);
  }
};

int main(void)
{
  string names[]={"김일이", "이일이", "삼사오", "사칠팔"};
  
  vector<string> vs(names, &names[sizeof(names)/sizeof(string)]);

  vector<string>::iterator it;

  it = find_if(vs.begin(), vs.end(), IsKim());
  if (it == vs.end())
    printf("nono\n");
  else
    printf("yea\n");
  return 0;
}
