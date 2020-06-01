#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

void functor1(int a)
{
  cout << a << ' ';
}

struct functor2{
  void operator()(double a) const
  {
    cout << a << endl;
  }
};

int main(void)
{
  int ari[] = {1,2,3,4,5,6};

  vector<int> vi(ari, &ari[sizeof(ari)/sizeof(int)]);

  double ard[] = {1.2, 3.4, 5.6, 7.8, 9.9};
  list<double> ld(ard, &ard[sizeof(ard)/sizeof(double)]);

  for_each(vi.begin(), vi.end(), functor1);
  cout << endl;
  for_each(ld.begin(), ld.end(), functor2());
}
