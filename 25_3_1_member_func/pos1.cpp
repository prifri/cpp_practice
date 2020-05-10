#include <iostream>

using namespace std;

struct position{
  int x;
  int y;
  char ch;
};

void putch(char ch)
{
  cout << ch << endl;
}

void gotoxy(int x, int y)
{
#if 0
  for (int i=y; i > 0 ; i--)
    cout << endl;

  for (int i=x; i > 0 ; i--)
    cout << " ";
#else
   printf("%c[%d;%df",0x1B,y,x);
#endif
}

void outposition(position *pos)
{
  gotoxy(pos->x, pos->y);
  putch(pos->ch);
}

int main()
{
  position here;
  here.x = 30;
  here.y = 10;
  here.ch = 'a';
  outposition(&here);
  return 0;
}
