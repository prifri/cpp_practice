#include <iostream>
#include "../include/comm.h"

using namespace std;

class Graphic{
  public:
    /*
     * https://stackoverflow.com/questions/2951273/pure-specifier-on-function-definition
     * C++ 표준이 아니랜다.
     * 이렇게 쓰지말고 생성자에 넣는게 정석이래
     */
#if 0 //    virtual void Draw()=0
    {
      clrscr();
    }
#else
    Graphic(void)
    {
      clrscr();
    }
    virtual void Draw()=0;
#endif
    virtual ~Graphic(void)
    {
    }
};

class Line : public Graphic{
  public:
    virtual void Draw(void)
    {
      puts("Line");
    }
};

class Circle : public Graphic{
  public:
    virtual void Draw(void)
    {
      puts("Circle");
    }
    virtual ~Circle(void)
    {
    }
};

int main(void)
{
  Graphic *pG[3];
  int i;

  pG[0] = new Line;
  pG[1] = new Circle;

  for (i=0; i<2; i++){
    pG[i]->Draw();
  }

  for (i=0; i<2 ; i++){
    delete pG[i];
  }
  return 0;
}
