#include <iostream>
#include "../include/comm.h"

using namespace std;

int main(void)
{
  string name, addr;
  cout << "name : ";
  cin >> name;
  cout << " name is " << name << " . " << endl;
  cin.ignore();
  cout << "address : ";
  getline(cin, addr);
  cout << " addr " << addr << ". " << endl;
  return 0;
}
