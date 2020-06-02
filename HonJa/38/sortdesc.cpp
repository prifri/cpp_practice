#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

void print(const string &name)
{
  cout << name << endl;
}

int main(void)
{
  string names[] = {"STL", "MFC", "owl", "html", "pascal", "Ada",
    "delphi", "C/C++", "Pyhon", "basic"};

  vector<string> vs(names, &names[sizeof(names)/sizeof(string)]);

  sort(vs.begin(), vs.end());

  for_each(vs.begin(), vs.end(), print);

  cout << endl << endl;
  sort(vs.begin(), vs.end(), greater<string>());
  for_each(vs.begin(), vs.end(), print);
  return 0;
}
