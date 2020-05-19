#include <iostream>
#include "../include/comm.h"
#include <cstring>

using namespace std;

template <typename T>

T add_my(T a, T b)
{
  return a+b;
}

/*
 * 실제로 동적 메모리를 이런시긍로 썻다간 뚝빼기 깨진다.
 * a에 strcat 을 쓰기위해선 a에 할당된 사이즈를 미리 알아야되는데
 * 일단 예제상으로는 구현이 불가하므로 적당히 이렇게만 만들어본다.
 * 또한 strcat대신 strncat_s를 무조건 써야됨.
 * strncat_s가 없다면 strncat을 쓰되 반드시 src 사이즈 검사를 미리
 * 수행해야함
 *
 * 아래식도 add_my(add_my(a,b),c)
 * 이런식으로 쓰면 메모리가 안드로메다로 가기 때문에 안된다.
 * 차라리 class나 구조체 만들어 생성자, 파괴자, operator등 구현해서
 * 쓰는게 안전..
 * 
 * 걍 예제때문에 적당히 한거같은데 더 좋은 예제였으면 좋았을거 같다.
 */
template <> char *add_my<char *>(char *a, char *b)
{
  int len_a = strlen(a), len_b = strlen(b);
  char *result = new char[len_a+len_b+1];
  
  strcpy(result, a);
  strcpy(&result[len_a], b);
  return result;
}

int main(void)
{
  int ia = 3, ib = 4, ic = add_my(ia, ib);
  double da = 1.2, db = 2.3, dc = add_my(da, db);
  char sa[] = "aaa", sb[] = "bbb", *sc = add_my(sa, sb);

  printf("ia %d ib %d ic %d\n", ia, ib, ic);
  printf("da %lf db %lf dc %lf\n", da, db, dc);
  printf("sa %s, sb %s, sc %s\n", sa, sb, sc);

  delete []sc;
  return 0;
}
