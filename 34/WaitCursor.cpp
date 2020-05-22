#include <iostream>
#include <X11/Xlib.h>
#include <X11/Xcursor/Xcursor.h>
#include <X11/cursorfont.h>

#include "../include/comm.h"
using namespace std;

class WaitCursor{
 private:
  void SetCursor(unsigned int shape)
  {
    Display *dpy = XOpenDisplay(NULL);
    Window w = RootWindow(dpy, 0); 
    Cursor c = XCreateFontCursor(dpy, shape);
    XDefineCursor (dpy, w, c);
    XFlush(dpy);
    XFreeCursor(dpy, c);
    XCloseDisplay(dpy);
  }

 public:
  WaitCursor()
  {
    SetCursor(XC_watch);
  }
  ~WaitCursor()
  {
    SetCursor(XC_left_ptr);
  }
};

void LongCalc(void)
{
  WaitCursor C;
  delay_ms(2000);
}

/*
 * 터미널을 선택한 상태에서 터미널 밖에 마우스 커서를 나둬야 잘보임
 * 터미널창에 마우스커서가 가리키고 있을때 기본커서로 계속나오는데
 * 한 2시간 공들여봤으나 
 *
 * X11은 창을 아에 새로띄워서 초기화시키는 것말곤
 * 힘들거나 shell command 날려서 default 설정을 on/off해야하던듯..
 *
 * QT나 GTK로 하면 더 좋긴하겠지만 그건 너무 돌아가는 느낌이므로 패스
 */
int main(void)
{
  if (true){
    LongCalc();
    cout << "Creae OBJ. check mouse pointer..." << endl;
    delay_ms(2000);
  }

  cout << "Destroy OBJ. Recovery mouse Pointer. Check.." << endl;
  delay_ms(2000);
  cout << "Ok. Bye" << endl;
  return 0;
}
