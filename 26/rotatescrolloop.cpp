#include <iostream>
#include <cstring>
#include "../include/comm.h"
using namespace std;

class rotatescroll{
  private:
    char *str;
    int str_len;

    char *x_area;
    int x_area_len;
    int x_s, y, speed, vector;
    int pos;
    int space_cnt;
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
      pos = 0;

      str_len = strlen(arg_str);
      x_area_len = arg_x_e - x_s + 1; //'\0 + first
      space_cnt = x_area_len - str_len;
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
  if (c_speed++ < speed)
    return;

  c_speed = 0;

  gotoxy(x_s, y);

  if (startup_char_cnt){
#if 1
    if (vector == true){
      memmove(x_area+1, x_area, startup_char_cnt - 1);
      *x_area = str[str_len - startup_char_cnt];
    }
    else{
      char *end_p = x_area + x_area_len - 1;
      memmove(end_p - 1 - startup_char_cnt + 1,
          end_p - startup_char_cnt + 1,
          startup_char_cnt - 1);
      *end_p = str[startup_char_cnt - 1];
    }

    if (startup_char_cnt == str_len ||
        startup_char_cnt == x_area_len)
      startup_char_cnt = 0;
    else
      startup_char_cnt++;
#else
    startup_char_cnt = 0;
#endif
  }
  else {
    if (space_cnt >= 0){
      char *p = x_area;
      /*
       * pos is x_area position
       *  +- pos < str_len
       *  |
       * [ABCD     ]
       *       +- pos >= str_len
       * [ABCD     ]
       */
      if (pos < str_len){
        int len = str_len - pos;
        memcpy(p, &str[pos], len);
        p += len;
        memset(p, ' ', space_cnt);
        p += space_cnt;
        memcpy(p, str, x_area_len - len - space_cnt);
      }
      else{
        int len = x_area_len - pos;

        memset(p, ' ', len);
        p += len;
        memcpy(p, str, str_len);
        p += str_len;
        memset(p, ' ', space_cnt - len);
      }
      if (vector == true){
        if (pos-- == 0)
          pos = x_area_len-1;
      }
      else{
        if (++pos >= x_area_len)
          pos = 0;
      }
    }
    else{
      /*
       * str : ABC
       *
       * pos is string position
       *  +-pos + x_area_len <= str_len
       * [AB]
       *
       *  +-pos + x_area_len <= str_len
       * [BC]
       *
       *  +-pos + x_area_len > str_len
       * [CA]
       */
      if (pos + x_area_len <= str_len){
        memcpy(x_area, &str[pos], x_area_len);
      }
      else{
        int len = str_len - pos;
        memcpy(x_area, &str[pos], len);
        memcpy(&x_area[len], str, x_area_len - len);
      }

      if (vector == true){
        if (pos-- == 0)
          pos = str_len-1;
      }
      else{
        if (++pos >= str_len)
          pos = 0;
      }
    }
  }
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
  for (clrscr();kbhit();){
    r1.rotate();
    r2.rotate();
    r3.rotate();
    r4.rotate();
    r5.rotate();
    r6.rotate();
    delay_ms(20);
  }

  return 0;
}
