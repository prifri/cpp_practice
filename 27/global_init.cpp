#include <iostream>
#include "../include/comm.h"
#include <valarray>

#include <X11/Xlib.h>
#include <X11/extensions/Xrandr.h>

using namespace std;

class Shape{
  private:
    int shape_tpe;
  public:
    static int scrx, scry;
    static void GetScreenSize();
};

int Shape::scrx;
int Shape::scry;

void Shape::GetScreenSize()
{
  int num_sizes;
  Rotation original_rotation;
  Display *dpy = XOpenDisplay(NULL);
  Window root = RootWindow(dpy, 0);
  XRRScreenSize *xrrs = XRRSizes(dpy, 0, &num_sizes);

  XRRScreenConfiguration *conf = XRRGetScreenInfo(dpy, root);
  XRRConfigCurrentRate(conf);
  SizeID original_size_id =
    XRRConfigCurrentConfiguration(conf, &original_rotation);
  scrx = xrrs[original_size_id].width;
  scry = xrrs[original_size_id].height;
  XCloseDisplay(dpy);
}

int main(void)
{
  Shape::GetScreenSize();
  Shape C, E, R;
  printf("display size = (%d, %d)\n",
      Shape::scrx, Shape::scry);
  return 0;
}
