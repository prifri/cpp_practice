#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(void)
{
  int ari[] = {1,2,3,4,5,6,7,8,9,10};

  vector<int> vi(ari, &ari[sizeof(ari)/sizeof(int)]);

  vector<int>::iterator it;
  auto func = [](int a){return (a%3 == 0);};

  for (it = vi.begin() ; it != vi.end() ; it++){
    it=find_if(it, vi.end(), func);
    if (it == vi.end())
      break;
    cout << *it << "." << endl;
  }

  return 0;
}
