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
      if (len >= 40){
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
}Num;

int main(void)
{
  CalType n;

  if (Num.In(n) < 0){
    std::cout << "invalid first number" << std::endl;
    return -1;
  }

  /*
   * 수는 두개가 존재한다.
   * n = 입력값
   * div_n = 나누는값
   * div_base_n = 나누는값을 입력값에서 구할때 쓰는 나누는값
   * 1. 입력값이 짝수일 경우 홀수부터 시작한다.
   * 2. 나누는값은 입력값을 홀수로 나눈 값을 의미한다.
   * 3. 이때 나누는값을 구하는 홀수는 
   * 3부터 시작하며 이후 2씩 증가하며 홀수로만 나눈다.
   *
   *
   * 나누는값보다 나눌때 구하는 홀수값이 커지는 경우
   * 소수로 인정 한다.
   * div_n으로 나눔으로써 div_base_n으로 나눈것과 같은 효과가 있기
   * 때문이다. 이경우 나눌수있는 모든 수로 나눴다고 판단된다.
   *
   * 입력값은 -2 씩빼며 홀수만을 계산한다.
   *
   * 걍 대충생각해서 짜봣더니 어찌되긴되는데 느릴듯..
   *
   * 소수 결과 검산
   * https://www.alpertron.com.ar/ECM.HTM
   */
  if ((n&1) == 0 && n>2){
    n--;
  }
  else if (n < 1){
    std::cout << " invalid numver." << std::endl;
    return -1;
  }

  while (n > 2){
    CalType div_base_n = 3;
    while (1){
      CalType div_n = n/div_base_n;
      if ((div_n&1) == 0)
        div_n--;

      if(div_n < div_base_n){
        std::cout << "max prime ";
        if (Num.Is128((__uint128_t)n) == true){
          Num.pr_128(n);
          std::cout << std::endl;
        }
        else{
          std::cout << (uint64_t)n << std::endl;
        }
        return 0;
      }
      else if (n%div_n == 0){
        break;
      }

      div_base_n += 2;
    }
    n -= 2;
  }

  std::cout << "max prime 2"  << std::endl;
  return 0;
}
