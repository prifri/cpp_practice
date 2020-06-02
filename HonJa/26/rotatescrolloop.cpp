#include <iostream>
#include <cstring>
#include "../include/comm.h"
using namespace std;

#define CS_OFF    "\033[?12l"
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
  rotatescroll r1("scroll object", 30, 50, 12, 2, true);
  rotatescroll r2("object oriented programming", 10, 60, 8, 3, false);
  rotatescroll r3("the c++ programming language", 5, 70, 18, 8, false);
  rotatescroll r4("---------->", 40, 75, 3, 0, true);
  rotatescroll r5("<======::====", 20, 75, 4, 0, false);
  rotatescroll r6("1234567890", 15, 20, 5, 0, false);
  rotatescroll r7("abcd", 5, 8, 1, 1, true);
  init(0);
  for (clrscr();!kbhit();){
    r1.rotate();
    r2.rotate();
    r3.rotate();
    r4.rotate();
    r5.rotate();
    r6.rotate();
    r7.rotate();
    delay_ms(20);
  }

  return 0;
}
