#include <iostream>
#include <cstring>
#include "../include/comm.h"

using namespace std;

#define CNT_MAX  1024
#define MAX_DISTANCE 100
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


  public:
    signal(void);

    void generate(char arg_ch = ' ', int arg_distance = 0, int arg_frame = 0);
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

void signal :: generate(char arg_ch, int arg_distance, int arg_frame)
{
  x = random(80);
  y = 0;
  if (arg_ch == '0')
    ch = random('Z' - 'A' + 1) + 'A';
  else
    ch = arg_ch;

  if (arg_distance == 0)
    distance = random(MAX_DISTANCE-MIN_DISTANCE) + MIN_DISTANCE;
  else
    distance = min(max(arg_distance, MIN_DISTANCE), MAX_DISTANCE);

  if (arg_frame == 0)
    nstay = nframe = random(MAX_FRAME-MIN_FRAME) + MIN_FRAME;
  else
    nstay = nframe = min(max(arg_frame, MIN_DISTANCE), MAX_DISTANCE);
  exist = true;

#if 0
  cstr = get_color(ch%MAX_E_ANSI_COLOR);
#else
  cstr = get_color(random(MAX_E_ANSI_COLOR-1));
#endif
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
    void run(char arg_ch = '0', int arg_distance = 0, int arg_frame = 0)
    {
      if (random(freq) == 0){
        for (int i=cnt-1; i>=0 ; i--)
        {
          signal *p = &s[i];
          if (p->is_exist() == false){
            p->generate(arg_ch, arg_distance, arg_frame);
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

class BlinkMessage
{
  private:
    bool bShow;
    int x, y;
    char *Mes;
    char *MesErase;
    int nFrame, Freq;

  public:
    BlinkMessage(int ax, int ay, const char *aMes, int anFrame) : 
      x(ax), y(ay), nFrame(anFrame)
  {
    int MesLen = strlen(aMes);
    Mes = (char *)malloc(MesLen + 1);
    MesErase = (char *)malloc(MesLen +1);
    strcpy(Mes, aMes);
    memset(MesErase, ' ', MesLen);
    MesErase[MesLen] = '\0';

    bShow = false;
    Freq = anFrame;
  }
    ~BlinkMessage(void)
    {
      free(Mes);
    }
    void Blink();
};

void BlinkMessage :: Blink()
{
  if (--Freq == 0){
    Freq = nFrame;
    if (bShow == false){
      gotoxy(x, y);
      puts(MesErase);
    }
    else{
      gotoxy(x, y);
      puts(Mes);
    }
    bShow = !bShow;
  }
}

class rotatescroll{
  private:
    char *str;
    int str_len;

    char *x_area;
    int x_area_len;
    int x_s, y, speed, vector;
    int str_pos;
    int space_cnt;
    int c_space_cnt;
    int c_speed;

    int startup_char_cnt;
  public:
    rotatescroll(const char *arg_str, int arg_x_s, int arg_x_e,
        int arg_y, int arg_speed, int arg_vector)
    {
      //arg fixup
      if (arg_x_s > arg_x_e){
        int tmp = arg_x_s;
        printf("start is bigger than end (%d %d)\n", arg_x_s, arg_x_e);
        arg_x_s = arg_x_e;
        arg_x_e = tmp;
        printf("fixup start : %d, end : %d\n", arg_x_s, arg_x_e);
      }

      //arg set
      x_s = arg_x_s;
      y = arg_y;
      speed = arg_speed;
      vector = arg_vector;

      c_speed = speed;
      str_pos = 0;

      str_len = strlen(arg_str);
      x_area_len = arg_x_e - x_s + 1; //'\0 + first
      space_cnt = x_area_len - str_len;
      c_space_cnt = 0;
      if (vector == true)
        str_pos = str_len - 1;
      else
        str_pos = 0;
      startup_char_cnt = 1;

      //str init
      str = new char[str_len+1];
      strcpy(str, arg_str);


      //x_area init
      x_area = new char[x_area_len +1];
      memset(x_area, ' ', x_area_len);
      x_area[x_area_len] = '\0';
    }

    ~rotatescroll(void)
    {
      delete str;
      delete x_area;
    }

    void rotate(void);
};

void rotatescroll::rotate(void)
{
  if (c_speed-- > 0)
    return;

  c_speed = speed;

  if (vector == true){
    memmove(x_area+1, x_area, x_area_len-1);

    if (str_pos >= 0){
      *x_area = str[str_pos--];
    }
    else if (space_cnt > 0){
      *x_area = ' ';
      if (c_space_cnt++ == space_cnt){
        c_space_cnt = 0;
        str_pos = str_len - 1;
      }
    }
    else{
      str_pos = str_len - 1 ;
      *x_area = str[str_pos--];
    }
  }
  else{
    memmove(x_area, x_area+1, x_area_len-1);
    if (str_pos < str_len){
      *(x_area + x_area_len - 1) = str[str_pos++];
    }
    else if (space_cnt > 0){
      *(x_area + x_area_len - 1) = ' ';
      if (c_space_cnt++ == space_cnt){
        c_space_cnt = 0;
        str_pos = 0;
      }
    }
    else{
      str_pos = 0;
      *(x_area + x_area_len - 1) = str[str_pos++];
    }
  }

  gotoxy(x_s, y);
  cout << x_area;
}

int main(void)
{
  signal_manager sm(999, 5);
#if 0
  BlinkMessage M(28, 10, "I N S E R T    C O I N", 20);
#else
  rotatescroll r("I N S E R T    C O I N", 10, 70, 12, 50, true);
#endif

  init(0);
  for (clrscr(); !kbhit(); delay_ms(5)){
    sm.run('.', 25,15);
#if 0
    M.Blink();
#else
    r.rotate();
#endif
  }
  return 0;
}
