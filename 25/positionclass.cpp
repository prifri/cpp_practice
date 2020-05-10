#include <iostream>
#include "../include/comm.h"

using namespace std;

class position{
  private:
    int x;
    int y;
    char ch;
  public:
    void init_rand(void)
    {
      x = random(80);
      y = random(24);
      ch = random('Z' - 'A' + 1) + 'A';
    }

    void out_pos(void)
    {
      gotoxy(x, y);
      putch(ch);
    }

    void erase_pos(void)
    {
      gotoxy(x, y);
      putch(' ');
    }
};

#define ARRAY_CNT   50
int main()
{
  position arpos[ARRAY_CNT];
  position *ppos;
  
  randomize();

  ppos = arpos;
  for (int i = ARRAY_CNT-1; i>= 0 ; i--){
    ppos->init_rand();
    ppos->out_pos();
    ppos++;
    delay_ms(50);
  }

  delay_ms(1000);

  ppos = arpos;
  for (int i = ARRAY_CNT-1; i>= 0 ; i--){
    ppos->erase_pos();
    ppos++;
    delay_ms(50);
  }
  return 0;
}
