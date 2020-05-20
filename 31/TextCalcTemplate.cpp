#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>

#define DEBUG_ON
#include "../include/comm.h"
#include "TStack.h"

#define DEBUG
using namespace std;

int GetPriority(int op)
{
  switch (op){
    case '(':
      return 0;
    case '+':
    case '-':
      return 1;
    case '*':
    case '/':
      return 2;
    case '^':
      return 3;
    default:
      return 100;
  }
}


void MakePostfix(char *Post, const char *Mid)
{
  const char *m = Mid;
  char *p = Post;

  TStack<char> cS(256);

  while (*m){
    if (isdigit(*m)) {
      while (isdigit(*m) || *m == '.')
        *p++ = *m++;
      *p++ = ' ';
    }else if (strchr("^*/+-", *m)){
      while (1){
        int top = cS.GetTop();
        if (top >= 0 && (GetPriority(cS.GetValue(top)) >=
                         GetPriority(*m))){
          *p++ = cS.Pop(NULL);
        }
        else
          break;
      }
      cS.Push(*m++);
    }
    else if (*m == '('){
      cS.Push(*m++);
    }
    else if(*m == ')'){
      while (1){
        bool result;
        char c = cS.Pop(&result);
        if (c == '(' || result == false)
          break;
        *p++ = c;
      }
      m++;
    }
    else{
      m++;
    }
    dpr("p : %s, m : %s, s : ", Post, m);
    cS.DbgShowStack(); dpr("\n");
  }

  while (cS.GetTop() != -1){
    *p++ = cS.Pop(NULL);
  }
  *p = '\0';
}

double CalcPostfix(const char *Post)
{
  const char *p = Post;
  double left, right;
  TStack<double> dS(256);

  while (*p) {
    dpr("Cp : %s, Cs : ", p);
    dS.DbgShowStack(); dpr("\n");
    /*
     * 숫자면 일단 스택에 쌓는다.
     */
    if (isdigit(*p)){
      dS.Push(atof(p));
      while (isdigit(*p) || *p == '.')
        p++;
    }
    /*
     * 쌓아놓았던 스택에서 숫자를 빼 연산한다.
     */
    else if (strchr("^*/+-", *p)){
      right = dS.Pop(NULL);
      left = dS.Pop(NULL);
      switch (*p) {
        case '+':
          dS.Push(left+right);
          break;
        case '-':
          dS.Push(left-right);
          break;
        case '*':
          dS.Push(left*right);
          break;
        case '/':
          dS.Push(left/right);
          break;
        default: //^
          dS.Push(pow(left, right));
          break;

      }
    }
    p++;
  }

  dpr("Cp : %s, Cs : ", p);
  dS.DbgShowStack(); dpr("\n");
  if (dS.GetTop() >= 0){
    return dS.Pop(NULL);
  }
  else
    return 0.0;
}

double CalcExp(const char *exp, bool *bError=NULL)
{
  char Post[256] = {0};

  if (bError){
    const char *p;
    int count;
    for (p=exp, count=0 ; *p ; p++){
      if(strchr("^*/+-", *p) == NULL){
        if (isdigit(*p) && *(p+1) == '('){
          *bError = true;
          return 0;
        }
        else if (*p == '('){
          count++;
        }
        else if (*p == ')'){
          if (isdigit(*(p+1))){
            *bError = true;
            return 0;
          }

          count--;
        }
      }
      else {
        char c = *(p+1);
        if (isdigit(c) == 0 && c != '(' && c != ')'){
          *bError = true;
          return 0;
        }
      }
    }
    *bError = (count != 0) ? true : false;
    if (*bError == true)
      return 0;
  }


  MakePostfix(Post, exp);
  return CalcPostfix(Post);
}

int main(void)
{
  char exp[256];
  bool bError;
  double result;
  char *p;

  strcpy(exp, "2.2+3.5*4.1");
  printf("%s = %.2f\n", exp, CalcExp(exp));
  memset(exp, 0, sizeof(exp));
  strcpy(exp, "(34+93)*2-(43/2)");
  printf("%s = %.2f\n", exp, CalcExp(exp));
  memset(exp, 0, sizeof(exp));

  strcpy(exp, "1+(2+3)/4*5+2^10+(6/7)*8");
  printf("%s = %.2f\n", exp, CalcExp(exp));
  memset(exp, 0, sizeof(exp));

  while (1){
    printf("수식입력 (끝낼때 0) : ");
#if 0 //gets는 폐기각 ㅇㅈㄸㅇㅈ
    gets(exp);
#else
    fgets(exp, sizeof(exp), stdin);
    p = exp;

#endif
    while (*p != '\0'){
      if (strchr("\r\n", *p)){
        *p = '\0';
      }
      p++;
    }

    if (strcmp(exp, "0") == 0)
      break;
    result = CalcExp(exp, &bError);
    if (bError)
      puts("수식 에러");
    else
      printf("%s = %.2f\n", exp, result);
  }
  return 0;
}
