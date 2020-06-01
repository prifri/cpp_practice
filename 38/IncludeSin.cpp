#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

struct prSin{
  bool operator()(string &name) const
  {
    if (strstr(name.c_str(), "신")){
      printf("%s\n", name.c_str());
      return true;
    }
    return false;
  }
};

int main(void)
{
  string names[]={"김일이", "이일신", "삼신오", "사칠팔", "신오육"};
  
  vector<string> vs(names, &names[sizeof(names)/sizeof(string)]);

  vector<string>::iterator it = vs.begin();

  while ((it = find_if(it, vs.end(), prSin())) != vs.end())
    it++;

  return 0;
}
