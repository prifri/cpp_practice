#include <iostream>
#include <cstring>
#include <iterator>
#include <ostream>
#include <vector>

#define __unused __attribute__((unused))
#if 0
typedef __uint128_t CalType ;
#else
typedef uint64_t CalType ;
#endif

#define DIGIT       10

class InNumber{
 public:
  int in(uint32_t &n)
  {
    std::cout << "input plus intger : ";
    std::cin >> n;

    if (std::cin.fail()){
      std::cout << "invalid number" << std::endl;
      return -1;
    }
    return 0;
  }

  int in(uint64_t &n)
  {
    std::cout << "input plus intger : ";

    std::cin >> n;

    if (std::cin.fail()){
      std::cout << "invalid number" << std::endl;
      return -1;
    }
    return 0;
  }

  int in(__uint128_t &n)
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

  void show(__uint128_t n)
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

/*
 * 참고 사이트
 * https://stackoverflow.com/questions/15704565/efficient-way-to-return-a-stdvector-in-c
 * https://dydtjr1128.github.io/cpp/2019/08/10/Cpp-RVO(Return-Value-Optimization).html
 */

template<typename T>
std::vector<T> prime_factor(T n)
{
  T origin = n;
  std::vector<T> factors;

  while (n % 2 == 0)
  {
    factors.push_back(2);
     n /= 2;
  }

  for (T i = 3; i <= Sqrt(n) ; i+= 2)
 {
   while ( n % i == 0)
   {
     factors.push_back(i);
     n /= i;
   }
 }

  if (n > 2 && n != origin)
  {
    factors.push_back(n);
  }

  return factors;
}

int main(int __unused argc, char __unused *argv[])
{
  CalType n;

  if (Num.in(n) < 0)
  {
    std::cout << "invalid number" << std::endl;
    return -1;
  }

  std::vector<CalType> factors = prime_factor(n);

#if 1
  for (const auto &i : factors)
  {
    std::cout << i << std::endl;
  }
#else
  for (std::vector<CalType>::iterator i = factors.begin() ;
       i != factors.end() ; i++)
  {
    std::cout << *i << std::endl;
  }
#endif
  return 0;
}
