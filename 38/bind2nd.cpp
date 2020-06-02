/*
 * https://en.cppreference.com/w/cpp/utility/functional/bind12
 * 
 *  (deprecated in C++11)
 *  (removed in C++17)
 *  bind gogo
 *
 * https://ozt88.tistory.com/51
 * https://stackoverflow.com/questions/32739018/a-replacement-for-stdbind2nd
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

struct IsMulti : public function<bool(int, int)>{
  bool operator()(int a, int b) const
  {
    return (a % b == 0);
  }
};

int main(void)
{
  int ari[] = {1,2,3,5,6,7,8,9,10};

  vector<int> vi(ari, &ari[sizeof(ari)/sizeof(int)]);

  vector<int>::iterator it;

  for (it = vi.begin(); it!=vi.end() ; it++){
#if 0
    it = find_if(it, vi.end(), bind2nd(IsMulti(), 3));
#else
    it = find_if(it, vi.end(), bind(IsMulti(), placeholders::_1, 3));
#endif
    if (it == vi.end())
      break;
    cout <<*it << "." << endl;
  }
  return 0;
}
