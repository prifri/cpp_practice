#include <iostream>
#include "../include/comm.h"

using namespace std;

class Draw{
 public:
  void GoXY(int x, int y, char ch = 0, const char *ansi = NULL)
  {
    if (ansi == NULL){
      gotoxy(x, y);
      if (ch)
        putch(ch);
    }
    else{
      gotoxy_color(x, y, ansi);
      if (ch)
        putch(ch);
      puts(ANSI_INIT);
    }
  }
  void GoXY(int x, int y, const char *str, const char *ansi = NULL)
  {
    if (ansi == NULL){
      gotoxy(x, y);
      puts(str);
    }
    else{
      gotoxy_color(x, y, ansi);
      puts(str);
      puts(ANSI_INIT);
    }
  }
};

/*
 * AAAAA
 * AAAAA
 * AAAAA
 * AAAAA
 */
class MainDisaply{
 private:
  Draw Dw;

  void draw_main_frame(void)
  {
    int x_len = 20;
    int y_len = 20;

    Dw.GoXY(1, 1, 1);
    Dw.GoXY(x_len+2, 1, 2);
    Dw.GoXY(1, y_len+2, 3);
    Dw.GoXY(x_len+2, y_len+2, 4);

    for (int i=0 ; i<x_len ; i++){
      Dw.GoXY(i+2, 1, 6);
      Dw.GoXY(i+2, y_len+2, 6);
    }

    for (int i=0 ; i<y_len ; i++){
      Dw.GoXY(1, i+2, '|');
      Dw.GoXY(x_len+2, i+2, '|');
    }

#if 0
    printf("\n\n");
    for (int i=150 ; i<256 ; i++){
      printf("%d = %c\n", i, i);
    }
#endif
  }
 public:
  MainDisaply(void)
  {
    draw_main_frame();
  }
};

int main(void)
{
  clrscr();

  MainDisaply Main;
  while (1){
    
    delay_ms(1000);
  }

  return 0;
}
