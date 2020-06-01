#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstring>

using namespace std;


/*
 * binary_function bye bye
 * 
 * http://egloos.zum.com/hellpme/v/1671958
 */
struct compare : public function<bool(string, string)>{
  bool operator ()(const string &a, const string &b) const
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

  sort(vs.begin(), vs.end(), not2(compare()));

  for_each(vs.begin(), vs.end(), print);
  return 0;
}
