#include <iostream>
#include "../include/comm.h"

using namespace std;

#define DEF_CH  ' '
class Signal{
  private:
    bool exist;
    char ch;
    int x,y;
    int distance;
    int nframe;
    int nstay;

    void hide(void)
    {
      gotoxy(x,y);
      putch(DEF_CH);
    }
    void Show(void)
    {
      gotoxy(x, y);
      putch(ch);
    }

  public:
    Signal(void)
    {
      exist = false;
    }

    bool IsExist(void) const
    {
      return exist;
    }

    void Generate(char arg_ch = DEF_CH, int arg_distance = 0, int arg_nframe = 0);
    void Move(void);
};

void Signal :: Generate(char arg_ch, int arg_distance, int arg_nframe)
{
  exist = true;
  if (arg_ch == DEF_CH)
    ch = random('Z'-'A'+1) + 'A';
  else
    ch = arg_ch;
  x = random(80);
  y = 0;

  if (arg_distance == 0)
    distance = random(14) + 9;
  else
    distance = arg_distance;

  if (arg_nframe == 0)
    nframe = nstay = random(15)+5;
  else
    nframe = nstay = arg_nframe;

  Show();
}

void Signal :: Move(void)
{
  if (--nstay == 0){
    nstay = nframe;
    hide();
    if (++y < distance)
      Show();
    else
      exist = false;
  }
}

int main(void)
{
#define MAX 4096
  Signal S[MAX];

  init (0);
  for (clrscr(), randomize(); !kbhit(); delay_ms(5)){
    if (random(15) == 0){
      for (int i=0; i<MAX ; i++){
        if (S[i].IsExist() == false){
          S[i].Generate();
          break;
        }
      }
    }

    for (int i=0; i<MAX ; i++){
      if (S[i].IsExist() == true){
        S[i].Move();
      }
    }
  }
  return 0;
}
