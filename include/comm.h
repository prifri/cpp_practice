#ifndef __COMM_H__
#define __COMM_H__

int kbhit(void);
void clrscr(void);
void gotoxy(int x, int y);
void putch(char ch);

void randomize(void);
int random(int range);
void delay_ms(int msec);
#endif
