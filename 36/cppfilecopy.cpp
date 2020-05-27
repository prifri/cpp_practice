#include <iostream>
#include "../include/comm.h"
#include <fstream>

using namespace std;

int main(void)
{
  ifstream src("./dummy", ios_base::in | ios_base::binary);
  if (src.is_open() == false){
    cout << "no" << endl;
    exit(0);
  }

  ofstream dst("./dummy2", ios_base::out | ios_base::binary | ios_base :: trunc);
  
#define SIZE 10000
  char buf[SIZE];

  while (1){
    src.read(buf, SIZE);
    int nread = src.gcount();

    if (nread == 0)
      break;
    dst.write(buf,nread);
  }

  src.close();
  dst.close();
  return 0;
}
