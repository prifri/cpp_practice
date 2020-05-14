#include <iostream>

//#define DEBUG_ON
#include "../include/comm.h"

#define MESSAGE_SIZE  128
using namespace std;

class car
{
  private:
    int gear;
    int angle;
    int rpm;
    char message[MESSAGE_SIZE];
  public:
    car(void)
    {
      gear = 0;
      angle = 0;
      rpm = 0;
    }

    void do_change_gear(int arg_gear)
    {
      if (arg_gear >= 0 && arg_gear <= 6){
        gear = arg_gear;
        return;
      }
//      cout << "change gear vaild is invalid " << arg_gear << endl;
    }

    void do_rotate_wheel(int delta){
      int temp_angle = angle + delta;
      if (temp_angle >= -45 && temp_angle <= 45){
        angle = temp_angle;
        return;
      }
  //    cout << "roate wheel value is invalid " << temp_angle << endl;
    }

    void do_accel(void)
    {
      rpm = min(rpm + 100, 3000);
    }

    void do_break(void)
    {
      rpm = max(rpm-500, 0);
    }

    void run(void);
};

void car :: run(void)
{
  int speed;

  gotoxy(10,12);
  if (gear == 0) {
    puts("input 1~6 key. set gear\n");
    return;
  }

  if (gear == 6){
    speed = rpm/100;
  }
  else {
    speed = gear*rpm/100;
  }

  snprintf(message, MESSAGE_SIZE, "기어 %d, %d의 속도로 %s쪽 %d도 방향으로 %s진중",
      gear, abs(speed), (angle >= 0 ? "오른":"왼"), abs(angle),
      gear == 6 ? "후":"진");
  puts(message);
}

int main(void)
{
  car c;
  int n = 0;
  char ch;

  init(0);
  while (1){
    gotoxy(10, 10);
    printf("1~5 : 기어 변속, 6: 후진 기어, 0: 기어 중립");
    gotoxy(10, 11);
    printf("위:액셀, 아래:브레이크, 좌우:핸들, Q:종료");
    /*
     * left : 27 68 91
     * right : 27 67 91
     * up : 27 65 27
     * down : 27 66 91
     */
    if (kbhit()){
      if ((ch = getchar()) == DIR_KEY__START){

        ch = getchar();
        switch (getchar()){
          case 68:
            dpr("<-\n");
            c.do_rotate_wheel(-5);
            break;
          case 67:
            dpr("->\n");
            c.do_rotate_wheel(5);
            break;
          case 65:
            dpr("up\n");
            c.do_accel();
            break;
          case 66:
            dpr("down\n");
            c.do_break();
            break;
          default:
            break;
        }
        getchar(); //filter DIR_KEY__END
      }
      else{
        if (ch >= '0' && ch <= '6'){
          c.do_change_gear(ch-'0');
        }
        else if (ch == ('q'|'Q')){
          goto out;
        }
      }
    }
    c.run();
    delay_ms(10);
  }

out:
  return 0;
}
