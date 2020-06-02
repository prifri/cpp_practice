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

  for (it = vi.begin() ; it != vi.end() ; it++){
    /*
     * 람다를 안쓸경우, bind 예제처럼 bind를 써야된다.
     * 거기다 함수포인터를 쓰기 싫은경우 함수객체까지 사용해된다.
     *
     * 굳이 인자를 한개줄이기 위한 작업으로
     * bind + 함수객체까지 만들어야된다? 짜는사람도 개빡치고
     * 보는사람도 개빡친다.
     * 이러한 경우 이렇게 람다로 해결할수가 있다.
     */
    it=find_if(it, vi.end(), [](int a){return (a % 3 == 0); });
    if (it == vi.end())
      break;
    cout << *it << "." << endl;
  }

  return 0;
}
