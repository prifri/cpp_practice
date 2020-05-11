#include <chrono>
#include <iostream>
#include <thread>
#include <cstdlib>
#include "../include/comm.h"

#include <stdio.h>
#include <unistd.h>
#include <termios.h>

using namespace std;

int kbhit(void)
{
  struct termios oldt, newt;
  int ch;

  tcgetattr( STDIN_FILENO, &oldt );
  newt = oldt;

  newt.c_lflag &= ~( ICANON | ECHO );
  tcsetattr( STDIN_FILENO, TCSANOW, &newt );

  ch = getchar();
  tcsetattr( STDIN_FILENO, TCSANOW, &oldt );

  return ch;
}

void clrscr(void)
{
  system("clear");
}

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
