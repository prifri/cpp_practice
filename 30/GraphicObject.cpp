#include <iostream>
#include "../include/comm.h"

using namespace std;

class Graphic{
  static int i;
  public:
  virtual ~Graphic(void)
  {
    cout << ++i << endl;
  }
  virtual void Draw(void)
  {
    cout << "Graphic" << endl;
  }
};

class Line : public Graphic{
  public:
    void Draw(void)
    {
      cout << "Line" << endl;
    }
};

class Circle : public Graphic{
  public:
    void Draw(void)
    {
      cout << "Circle" << endl;
    }
};

class Rect : public Graphic{
  public:
    void Draw(void)
    {
      cout << "Rect" << endl;
    }
};

int Graphic::i = 0;
int main(void)
{
  Graphic *ar[10] = {
    new Graphic(), new Rect(), new Circle(), new Rect(), new Line(),
    new Line(), new Rect(), new Line(), new Graphic(), new Circle()};
  int i;

  for (i=0; i<10 ; i++){
    ar[i]->Draw();
  }

  for (i=0; i<10 ; i++){
    delete ar[i];
  }
  return 0;
}
