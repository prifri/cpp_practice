#include <iostream>
#include <cstring>
#include <pthread.h>

#if 1
typedef __uint128_t CalType ;
#else
typedef uint32_t CalType ;
#endif

#define DIGIT       10

class InNumber{
 public:
  int In(uint32_t &n)
  {
    std::cout << "input plus intger : ";
    std::cin >> n;

    if (std::cin.fail()){
      std::cout << "invalid number" << std::endl;
      return -1;
    }
    return 0;
  }

  int In(uint64_t &n)
  {
    std::cout << "input plus intger : ";

    std::cin >> n;

    if (std::cin.fail()){
      std::cout << "invalid number" << std::endl;
      return -1;
    }
    return 0;
  }

  int In(__uint128_t &n)
  {
    char uint128_str[41];
    std::cout << "input plus intger : ";

    std::cin >> uint128_str;

    char *p = uint128_str;
    int len = 0;

    n = 0;
    while (*p != '\0'){
      n = n*10 + *p - '0';
      p++;
      len++;
      if (len >= 39){
        std::cout << "toooo large.." << std::endl;
        return -1;
      }
    }

    std::cout << "in : " << uint128_str << std::endl;
    if (std::cin.fail()){
      std::cout << "invalid number" << std::endl;
      return -1;
    }
    return 0;
  }

  void pr_128(__uint128_t n)
  {
    char str[40];
    int len = 0;
    __uint128_t tmp = n;
    while (tmp){
      len++;
      tmp /= 10;
    }

    str[len] = '\0';
    while (1){
      str[--len] = n%10 + '0';
      n/=10;
      if (len == 0)
        break;
    }

    std::cout << str;
  }

  bool Is128(__uint128_t n)
  {
    uint64_t max = -1;

    if (n > max)
      return true;
    return false;
  }

  void Show(__uint128_t n)
  {
    if (Is128(n) == true)
      pr_128(n);
    else
      std::cout << (uint64_t)n;
  }
}Num;

CalType power(CalType x, CalType y)
{
  CalType __x = 1;

  for (CalType i = y ; i > 0 ; i--){
    __x *= x;
  }
  return __x;
}

int g_thread_cnt = 1;
pthread_mutex_t g_mutex = PTHREAD_MUTEX_INITIALIZER;

void __arm2(CalType sum, CalType arm_sum, uint32_t digit,
            uint32_t deep, const CalType start, const CalType end)
{
  static int idx = 0;
  uint32_t ten = 1;
  uint32_t n = 0;
  CalType __sum = sum;
  CalType __arm_sum = arm_sum;

  for (uint32_t i=1; i<deep ; i++)
    ten *= 10;

  if (sum == 0){
    n = 1;
  }

  if (deep--){

    for ( ; n<10 ; n++){
      __sum = sum + n*ten;
      if (__sum < start)
        continue;
      else if (__sum >= end)
        return;

      __arm_sum = arm_sum + power(n, digit);

      if (__sum >= sum && __arm_sum >= arm_sum){
        if (deep == 0 && __sum == __arm_sum){
          pthread_mutex_lock(&g_mutex);
          printf("No.%u : ", ++idx);
          Num.Show((__uint128_t)__sum);
          printf("\n");
          pthread_mutex_unlock(&g_mutex);
        }
        else
          __arm2(__sum, __arm_sum, digit, deep, start, end);
      }
      else{
        printf("Over!\n");
        return;
      }
    }

  }


}

void *arm2(void *arg)
{
  int thread_num = (int)((intptr_t)arg);
  CalType end = power(10, DIGIT);
  CalType curr = end/10;
  CalType div = (end-curr)/(g_thread_cnt);
  CalType next;

  curr = div*thread_num + curr;
  next = curr + div;
  end = next <= end ? next : end;

#if 0
  printf("curr : "); Num.Show((__uint128_t)curr); printf("\n");
  printf("end : "); Num.Show((__uint128_t)end); printf("\n");
#endif
  __arm2(0, 0, DIGIT, DIGIT, curr, end);
  return NULL;
}

void *arm1(void *arg)
{
  static uint32_t idx = 0;
  uint32_t digit = DIGIT;
  int thread_num = (int)((intptr_t)arg);

#if 0
  std::cout << "digit in "<< std::endl;
  if (Num.In(digit) < 0){
    std::cout << "invalid number" << std::endl;
    return -1;
  }
#endif

  CalType end = power(10, digit);
  CalType curr = end/10;
  CalType div = (end-curr)/(g_thread_cnt);
  CalType next;

  curr = div*thread_num + curr;
  next = curr + div;
  end = next <= end ? next : end;

#if 0
  printf("curr : "); Num.Show((__uint128_t)curr); printf("\n");
  printf("end : "); Num.Show((__uint128_t)end); printf("\n");
#endif
  while (curr < end){
    CalType sum = 0;
    CalType tmp = curr;

    while (tmp){
      sum += power(tmp%10, digit);
      tmp /= 10;
    }

    if (sum == curr){
      pthread_mutex_lock(&g_mutex);
      std::cout << "No." << ++idx << " : ";
      Num.Show((__uint128_t)curr);
      std::cout << std::endl;
      pthread_mutex_unlock(&g_mutex);
    }
    curr++;
  }

  return NULL;
}

void do_arm1(int tcnt)
{
  if (tcnt <= 1){
    arm1(NULL);
  }
  else{
    pthread_t tid[tcnt];
    for (int i = 0 ; i<tcnt ; i++){
      pthread_create(&tid[i], NULL, arm1, (void *)(intptr_t)i);
    }
    for (int i = 0 ; i<tcnt ; i++){
      pthread_join(tid[i], NULL);
    }
  }
}

void do_arm2(int tcnt)
{
  if (tcnt <= 1){
    arm2(NULL);
  }
  else{
    pthread_t tid[tcnt];
    for (int i = 0 ; i<tcnt ; i++){
      pthread_create(&tid[i], NULL, arm2, (void *)(intptr_t)i);
    }
    for (int i = 0 ; i<tcnt ; i++){
      pthread_join(tid[i], NULL);
    }
  }
}

int main(int argc, char *argv[])
{
  time_t s = time(NULL);
  time_t e;

  if (argc != 1){
    g_thread_cnt = atoi(argv[1]);
    if (g_thread_cnt == 0){
      printf("invalid arg\n");
      return 0;
    }
    printf("thread cnt = %d\n", g_thread_cnt);
  }

  printf("arm 1\n");

  do_arm1(g_thread_cnt);

  e = time(NULL);
  printf("arm 1 end %lu sec\n", e-s);
  printf("\narm 2\n");

  s = e;
  do_arm2(g_thread_cnt);

  e = time(NULL);
  printf("arm 2 end %lu sec\n", e-s);
  return 0;
}
