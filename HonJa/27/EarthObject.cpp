#include <iostream>
#include "../include/comm.h"
#include <math.h>

using namespace std;

class Sun{
  private:
    int x,y;
    char ch;

  public:
    Sun(int a_x, int a_y, char a_ch) : x(a_x), y(a_y), ch(a_ch)
    {
    }

    void Show(void)
    {
      gotoxy(x, y);
      putch(ch);
    }

    void Hide(void)
    {
      gotoxy(x, y);
      putch(' ');
    }

    int GetX(void) const
    {
      return x;
    }

    int GetY(void) const
    {
      return y;
    }
};

class Earth{
  private:
    int r;
    int x,y;
    char ch;
    const Sun *pSun;

    void Show(void) {
      gotoxy(pSun->GetX() + x, pSun->GetY() + y);
      putch(ch);
    }

    void Hide(void) {
      gotoxy(pSun->GetX() + x, pSun->GetY() + y);
      putch(' ');
    }

  public:
    Earth(int a_r, char a_ch, Sun *a_pSun) : r(a_r), ch(a_ch), pSun(a_pSun)
    {
    }

    void Revolve(double angle){
      Hide();
      x = int(cos(angle*3.1416/180)*r*2);
      y = int(sin(angle*3.1416/180)*r);
      Show();
    }

    int GetX(void) const
    {
      return pSun->GetX() + x;
    }

    int GetY(void) const
    {
      return pSun->GetY() + y;
    }
};

class Moon{
  private:
    int r;
    int x,y;
    char ch;
    const Earth *pEarth;
    int before_x, before_y;

    void Show(void) {
      before_x = pEarth->GetX() + x;
      before_y = pEarth->GetY() + y;
      if ((before_x|before_y) > 0 ){
        gotoxy(before_x, before_y);
        putch(ch);
      }
    }

    void Hide(void) {
      if ((before_x|before_y) > 0 ){
        gotoxy(before_x, before_y);
        putch(' ');
      }
    }

  public:
    Moon(int a_r, char a_ch, Earth *a_pEarth) :
      r(a_r), ch(a_ch), pEarth(a_pEarth)
    {
      before_x = pEarth->GetX() + x;
      before_y = pEarth->GetY() + y;
    }

    void Revolve(double angle){
      Hide();
      x = int(cos(angle*3.1416/180)*r*2);
      y = int(sin(angle*3.1416/180)*r);
      Show();
    }

};

int main(void)
{
  clrscr();
  Sun S(40, 12, 'S');
  Earth E(10, 'E', &S);
  Moon M(3, 'M', &E);

  clrscr();
  init(0);
  S.Show();

  /*
   * sun : 1 == moon : 12
   */
  for (double angle=0; !kbhit() ; angle+=1){
    E.Revolve(angle);
    for (double angle2=angle*12; angle2 < (angle+1)*12 && !kbhit() ; angle2 += 1){
      M.Revolve(angle2);
      delay_ms(2);
    }
    delay_ms(2);
  }
  return 0;
}
