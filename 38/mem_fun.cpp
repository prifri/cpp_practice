#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

/*
 * https://stackoverflow.com/questions/11680807/stdmem-fun-vs-stdmem-fn
 * mem_fn go
 */
using namespace std;

class Natural{
 private:
  int num;
 public:
  Natural(int anum) : num(anum)
  {
    Setnum(anum);
  }

  void Setnum(int anum)
  {
    if (anum >= 0)
      num = anum;
  }

  int GetNum(void)
  {
    return num;
  }

  bool IsEven(void)
  {
    return num % 2 == 0;
  }
};

void delnatural(Natural *pn)
{
  delete pn;
}

int main(void)
{
  vector<Natural *> vn;
  vn.push_back(new Natural(1));
  vn.push_back(new Natural(2));
  vn.push_back(new Natural(3));
  vn.push_back(new Natural(4));

  vector<Natural *>::iterator it;
  for (it=vn.begin() ; it != vn.end() ; it++){
    it = find_if(it, vn.end(), mem_fn(&Natural::IsEven));
    if (it == vn.end())
      break;
    cout << (*it)->GetNum() << "." << endl;
  }
  for_each(vn.begin(), vn.end(), delnatural);
  return 0;
}
