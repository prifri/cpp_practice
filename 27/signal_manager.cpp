#include <iostream>
#include "../include/comm.h"

using namespace std;

#define CNT_MAX  1024
#define MAX_DISTANCE 15
#define MIN_DISTANCE 9
#define MAX_FRAME    15
#define MIN_FRAME    5
#define MAX_FREQ     150
class signal{
  private:
    int x, y, distance, nstay, nframe;
    bool exist;
    char ch;
    const char *cstr;

    void show(void)
    {
      gotoxy_color(x, y, cstr);
      putch(ch);
      puts(ANSI_INIT);
    }
    void hide(void)
    {
      gotoxy(x, y);
      putch(' ');
    }

    void make_signal(void)
    {
      x = random(80);
      y = 0;
      ch = random('Z' - 'A' + 1) + 'A';
      distance = random(MAX_DISTANCE-MIN_DISTANCE) + MIN_DISTANCE;
      nstay = nframe = random(MAX_FRAME-MIN_FRAME) + MIN_FRAME;
      exist = true;

      cstr = get_color(ch%MAX_E_ANSI_COLOR);
    }

  public:
    signal(void);

    void generate(void);
    void move(void);

    bool is_exist(void)
    {
      return exist;
    }
};

signal :: signal(void)
{
  exist = false;
}

void signal :: generate(void)
{
  make_signal();
  show();
}

void signal:: move(void)
{
  if (nstay-- == 0){
    hide();
    if (++y < distance){
      show();
      nstay = nframe;
    }
    else
      exist = false;
  }
}

class signal_manager{
  private:
    signal *s;
    int cnt;
    int freq;
  public:
    signal_manager(int arg_cnt, int arg_freq)
    {
      randomize();
      if (arg_cnt <= 0)
        cnt = 1024;
      else
        cnt = min(CNT_MAX, arg_cnt);

      if (arg_freq <= 0)
        freq = arg_freq;
      else
        freq = min(MAX_FREQ, arg_freq);

      s = new signal[cnt];
    }
    ~signal_manager(void)
    {
      delete []s;
    }
    void run(void)
    {
      if (random(freq) == 0){
        for (int i=cnt-1; i>=0 ; i--)
        {
          signal *p = &s[i];
          if (p->is_exist() == false){
            p->generate();
            break;
          }
        }
      }
      for (int i=cnt-1; i>=0 ; i--)
      {
        signal *p = &s[i];
        if (p->is_exist() == true){
          p->move();
        }
      }
    }
};

int main(void)
{
  signal_manager sm(999, 5);

  init(0);
  for (clrscr(); !kbhit(); delay_ms(5)){
    sm.run();
  }
  return 0;
}
