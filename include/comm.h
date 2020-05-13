#ifndef __COMM_H__
#define __COMM_H__

#ifdef DEBUG_ON
#define dpr(fmt, args...) printf(fmt, ##args)
#else
#define dpr(fmt, args...)
#endif

#define DIR_KEY__START    27
#define DIR_KEY__END      91
void enable_raw_mode();
void disable_raw_mode();
void init(int cursor);
int kbhit(void);
void clrscr(void);
void gotoxy(int x, int y);
void putch(char ch);

void randomize(void);
int random(int range);
void delay_ms(int msec);
#endif
