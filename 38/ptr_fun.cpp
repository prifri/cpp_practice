/*
 * https://stackoverflow.com/questions/44973435/stdptr-fun-replacement-for-c17
 *
 * 람다맨..
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
bool isMultiFunc(int a, int b)
{
  return (a % b == 0);
}

int main(void)
{
  int ari[] = {1,2,3,4,5,6,7,8,9,10};

  vector<int> vi(ari, &ari[sizeof(ari)/sizeof(int)]);

  vector<int>::iterator it;

  for (it = vi.begin() ; it != vi.end() ; it++){
#if 0
    it=find_if(it, vi.end(), bind2nd(isMultiFunc, placeholders::_1, 3));
#else
    /*
     * bind는 함수포인터 된다. 왜인지는 모른다 하하
     */
    it=find_if(it, vi.end(), bind(isMultiFunc, placeholders::_1, 3));
#endif
    if (it == vi.end())
      break;
    cout << *it << "." << endl;
  }

  return 0;
}
