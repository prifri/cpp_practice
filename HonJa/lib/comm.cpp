#include <chrono>
#include <iostream>
#include <thread>
#include <cstdlib>
#include "../include/comm.h"

#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <string.h>
#include <signal.h>

using namespace std;

#if 1
void enable_raw_mode()
{
  termios term;
  tcgetattr(0, &term);
  term.c_lflag &= ~(ICANON | ECHO); // Disable echo as well
  tcsetattr(0, TCSANOW, &term);
}

void disable_raw_mode()
{
  termios term;
  tcgetattr(0, &term);
  term.c_lflag |= ICANON | ECHO;
  tcsetattr(0, TCSANOW, &term);
}

int kbhit()
{
  int byteswaiting;
  ioctl(0, FIONREAD, &byteswaiting);
  return byteswaiting > 0;
}

#if 0
char getch() {
  char buf = 0;
  struct termios old;

  memset(&old, 0, sizeof(struct termios));
  if (tcgetattr(0, &old) < 0)
    perror("tcsetattr()");
  old.c_lflag &= ~ICANON;
  //  old.c_lflag &= ~ECHO;
  old.c_cc[VMIN] = 1;
  old.c_cc[VTIME] = 0;
  if (tcsetattr(0, TCSANOW, &old) < 0)
    perror("tcsetattr ICANON");
  if (read(0, &buf, 1) < 0)
    perror ("read()");
  old.c_lflag |= ICANON;
  old.c_lflag |= ECHO;
  if (tcsetattr(0, TCSADRAIN, &old) < 0)
    perror ("tcsetattr ~ICANON");
  return (buf);
}
#endif
#else
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

  printf("ch %d\n", ch);
  return ch;
}
#endif

void clrscr(void)
{
  system("clear");
}

void gotoxy(int x, int y)
{
  printf("%c[%d;%df",0x1B,y,x);
}

void gotoxy_color(int x, int y, const char *ansi)
{
  printf("%s%c[%d;%df", ansi, 0x1B,y,x);
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

void cursor_ctrl(int on)
{
  if (on)
    fputs("\e[?25h", stdout);
  //  system("setterm -cursor on");
  else
    fputs("\e[?25l", stdout);
  //system("setterm -cursor off");
}

static void deinit(void)
{
  disable_raw_mode();
  cursor_ctrl(1);
}

static void sig_deinit(__attribute__((unused)) int signo)
{
  exit(0);
}

void init(int cursor)
{
  enable_raw_mode();
  cursor_ctrl(cursor);
  atexit(deinit);
  signal(SIGHUP, sig_deinit);
  signal(SIGTERM, sig_deinit);
  signal(SIGINT, sig_deinit);

}

const char *get_color(int idx)
{
  switch (idx){
    case E_ANSI_INIT:
    case E_ANSI_RED:
      return ANSI_RED;
    case E_ANSI_GREEN:
      return ANSI_GREEN;
    case E_ANSI_YELLOW:
      return ANSI_YELLOW;
    case E_ANSI_BLUE:
      return ANSI_BLUE;
    case E_ANSI_MAGENTA:
      return ANSI_MAGENTA;
    case E_ANSI_CYAN:
      return ANSI_CYAN;
    case E_ANSI_BLACK:
      return ANSI_BLACK;
    default:
      return ANSI_INIT;
  }
}
