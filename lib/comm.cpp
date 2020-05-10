#include <chrono>
#include <iostream>
#include <thread>
#include <cstdlib>
#include "../include/comm.h"

using namespace std;

void gotoxy(int x, int y)
{
  printf("%c[%d;%df",0x1B,y,x);
}

void putch(char ch)
{
  cout << ch << endl;
}

void randomize(void)
{
  srand(time(NULL));
}

int random(int ragnge)
{
  return rand()%ragnge;
}

void delay_ms(int msec)
{
  std::this_thread::sleep_for (std::chrono::milliseconds(msec));
}
