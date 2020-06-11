#include <iostream>
#include <cstring>

#if 0
typedef __uint128_t CalType ;
#else
typedef uint32_t CalType ;
#endif

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

template <typename T>
T Sqrt (T a)
{
  T min = 0;
  T max = ((T) 1) << (sizeof(T)*4);
  while(1)
    {
       if (max <= 1 + min)
         return min;

       T sqt = min + (max - min)/2;
       T sq = sqt*sqt;

       if (sq == a)
         return sqt;

       if (sq > a)
         max = sqt;
       else
         min = sqt;
    }
}

template <typename T>
T SumDivisor(T n)
{
  T Start = 2;
  T Max = Sqrt(n);
  T ret = 1;

  while (Start <= Max){
    if (n%Start == 0){
      T div = n/Start;
      if (div == Start)
        ret += Start;
      else
        ret += Start + div;
    }
    Start++;
  }

  return ret;
}

int main(void)
{
  int idx = 0;
  CalType n = 1;
  CalType max = 1000000;

#if 0
  std::cout << "Min in "<< std::endl;
  if (Num.In(n) < 0){
    std::cout << "invalid first number" << std::endl;
    return -1;
  }

  std::cout << "Max in "<< std::endl;
  if (Num.In(max) < 0){
    std::cout << "invalid first number" << std::endl;
    return -1;
  }
#endif

  while (n <= max){
    CalType Sum = SumDivisor(n);
    if (n > Sum){
      CalType Sum2 = SumDivisor(Sum);
      if (Sum2 == n){
        std::cout << "No." << ++idx << " : ";
        Num.Show(Sum);
        std::cout << " , ";
        Num.Show(n);
        std::cout << std::endl;
      }
    }
    n++;
  }

  return 0;
}
