#include <iostream>
#include <cstring>

typedef __uint128_t CalType ;

class InNumber{
 public:
  int In(int &n)
  {
    std::cout << "input plus intger : ";
    std::cin >> n;

    if (std::cin.fail() || n < 2){
      std::cout << "invalid number" << std::endl;
      return -1;
    }
    return 0;
  }

  int In(uint64_t &n)
  {
    std::cout << "input plus intger : ";

    std::cin >> n;

    if (std::cin.fail() || n < 2){
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
    if (std::cin.fail() || n < 2){
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
bool IsPrim(T n)
{
  T div_base_n = 3;
  while (1){
    T div_n = n/div_base_n;
    if ((div_n&1) == 0)
      div_n--;

    if(div_n < div_base_n){
      return true;
    }
    else if (n%div_n == 0){
      break;
    }

    div_base_n += 2;
  }
  return false;
}

int main(void)
{
  int idx = 0;
  CalType n = 3;
  CalType max;
  CalType PrimeStore[3] = {0, 0, 0};

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

  if (max < 6){
    std::cout << "Max Input over 6" << std::endl;
    return -1;
  }

  while (n <= max){
    if (IsPrim<CalType>(n) == true){
      for (int i=0; i<3; i++){
        if (n == PrimeStore[i]+6){
          std::cout << "Sexy Prim(" << ++idx << ") ";
          Num.Show((__uint128_t)n);
          std::cout << " ";
          Num.Show((__uint128_t)PrimeStore[i]);
          std::cout << std::endl;
        }
      }
      PrimeStore[2] = PrimeStore[1];
      PrimeStore[1] = PrimeStore[0];
      PrimeStore[0] = n;
    }

    n += 2;
  }

  return 0;
}
