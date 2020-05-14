#ifndef __COMM_H__
#define __COMM_H__

#ifdef DEBUG_ON
#define dpr(fmt, args...) printf(fmt, ##args)
#else
#define dpr(fmt, args...)
#endif

#define DIR_KEY__START    27
#define DIR_KEY__END      91


#define ANSI_INIT               "\033[0m"
#define ANSI_BLINK              "\033[5m"
#define ANSI_BLACK              "\033[0;30m"
#define ANSI_RED                "\033[0;31m"
#define ANSI_GREEN              "\033[0;32m"
#define ANSI_YELLOW             "\033[0;33m"  
#define ANSI_BLUE               "\033[0;34m"
#define ANSI_MAGENTA            "\033[0;35m"  
#define ANSI_CYAN               "\033[0;36m"  
#define ANSI_DEFAULT            "\033[0;39m"
typedef enum {
  E_ANSI_INIT,
  E_ANSI_RED,
  E_ANSI_GREEN,
  E_ANSI_YELLOW,
  E_ANSI_BLUE,
  E_ANSI_MAGENTA,
  E_ANSI_CYAN,
  MAX_E_ANSI_COLOR,
  E_ANSI_BLACK = MAX_E_ANSI_COLOR,
  MAX_E_ANSI
}e_ansi;

#define ANSI_LGRAY              "\033[0;37m"
#define ANSI_GRAY              "\033[0;90m"  
#define ANSI_BRED               "\033[0;91m"  
#define ANSI_BGREEN             "\033[0;92m"  
#define ANSI_BYELLOW            "\033[0;93m"  
#define ANSI_BBLUE              "\033[0;94m"  
#define ANSI_BMAGENTA           "\033[0;95m"  
#define ANSI_BCYAN              "\033[0;96m" 
#define ANSI_BWHITE              "\033[0;97m"

void enable_raw_mode();
void disable_raw_mode();
void init(int cursor);
int kbhit(void);
void clrscr(void);
void gotoxy(int x, int y);
void gotoxy_color(int x, int y, const char *ansi);
void putch(char ch);

void randomize(void);
int random(int range);
void delay_ms(int msec);
const char *get_color(int idx);
#endif
