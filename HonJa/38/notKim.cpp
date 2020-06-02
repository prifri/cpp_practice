#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <functional>

using namespace std;

struct IsKim : public function<bool(string)>{
  bool operator()(const string &name) const
  {
    return strncmp(name.c_str(), "김", 2);
  }
};

int main(void)
{
  string names[]={"김일이", "이일신", "김신오", "사칠팔", "신오육"};
  
  vector<string> vs(names, &names[sizeof(names)/sizeof(string)]);

  vector<string>::iterator it = vs.begin();

  while ((it = find_if(it, vs.end(), not1(IsKim()))) != vs.end()){
    cout << *it << endl;
    it++;
  }

  return 0;
}
