#include <iostream>
#include "../include/comm.h"
#include <atomic>

#include <mutex>
#include <thread>
#include <vector>
/*
 * *
 * * spin lock implemented by C++ std::atomic
 * *
 * */

class SpinLock {
  std::atomic_flag locked = ATOMIC_FLAG_INIT ;
  public:
  void lock() {
    while (locked.test_and_set(std::memory_order_acquire)) { ; }
  }
  void unlock() {
    locked.clear(std::memory_order_release);
  }
};

using namespace std;

class pos{
  private:
    int x,y;
    char ch;
#define INFO_SIZE   256
    mutable char info[INFO_SIZE];
    mutable SpinLock spinlock;

  public:
    pos(int a_x, int a_y, char a_ch) : x(a_x), y(a_y), ch(a_ch)
    {
    }

    void out_pos(void) const
    {
      gotoxy(x, y);
      putch(ch);
    }

    void move_to(int a_x, int a_y)
    {
      x = a_x;
      y = a_y;
    }

    void make_info(void) const {
      spinlock.lock();
      snprintf(info, INFO_SIZE, "x = %d, y = %d, ch = %c", x, y, ch);
      spinlock.unlock();
    }

    void out_info(void) const {
      spinlock.lock();
      puts(info);
      spinlock.unlock();
    }
};

int main(void)
{
  const pos here(11, 2, 'z');
  here.make_info();
  here.out_info();
  return 0;
}
