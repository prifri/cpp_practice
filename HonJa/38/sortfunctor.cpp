#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstring>

using namespace std;

struct compare{
  bool operator ()(const string &a, const string &b)
  {
    return strcmp(a.c_str(), b.c_str()) < 0;
  }
};
void print(const string &name)
{
  cout << name << endl;
}

int main(void)
{
  string names[] = {"STL", "MFC", "owl", "html", "pascal", "Ada",
    "delphi", "C/C++", "Pyhon", "basic"};

  vector<string> vs(names, &names[sizeof(names)/sizeof(string)]);

  sort(vs.begin(), vs.end(), compare());

  for_each(vs.begin(), vs.end(), print);
  return 0;
}
