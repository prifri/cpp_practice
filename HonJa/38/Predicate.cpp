#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

/*
 * unary_function bye bye
 * 
 * http://egloos.zum.com/hellpme/v/1671958
 */
using namespace std;

struct isMulti3 : public function<bool(int)> {
  typedef int argument_type;
  typedef void result_type;
  bool operator()(int a) const
  {
    return (a%3 == 0);
  }
};

int main(void)
{
  int ari[] = {1,2,3,45,5,6,7,9,10};

  vector<int> vi(ari, &ari[sizeof(ari)/sizeof(int)]);

  vector<int>::iterator it = vi.begin();

  while (1){
    it = find_if(it, vi.end(), isMulti3());
    if (it == vi.end())
      break;
    cout << *it << "." << endl;
    it++;
  }

  cout << endl << endl;


  it = vi.begin();
  while (1){
    it = find_if(it, vi.end(), not1(isMulti3()));
    if (it == vi.end())
      break;
    cout << *it << "." << endl;
    it++;
  }

  return 0;
}
