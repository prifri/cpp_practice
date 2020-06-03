#include <iostream>
#include <numeric>

int in_number(int &n)
{

  std::cout << "input plus intger : ";
  std::cin >> n;

  if (n < 2){
    std::cout << "invalid number" << std::endl;
    return -1;
  }
  return 0;
}
#if 0

int main(void)
{
  int n1, n2;

  if (in_number(n1) < 0){
    std::cout << "invalid first number" << std::endl;
    return -1;
  }

  if (in_number(n2) < 0){
    std::cout << "invalid first number" << std::endl;
    return -1;
  }

  int limit = n1 < n2 ? n1 : n2;
  int gcd_result = 0;

  if (n1%limit == 0 && n2%limit == 0){
    gcd_result = limit;
  }
  else{
    int curr_n = limit/2;

    while (1){
      if (curr_n <= 1)
        break;
      if (n1%curr_n == 0 && n2%curr_n == 0){
        gcd_result = curr_n;
        break;
      }
      curr_n--;
    }
  }

  if (gcd_result)
    std::cout << "gcd_result : " << gcd_result << std::endl;
  else
    std::cout << "not exist gcd_result" << std::endl;
  return 0;
}
#else

int main(void)
{
  int n1, n2;

  if (in_number(n1) < 0){
    std::cout << "invalid first number" << std::endl;
    return -1;
  }

  if (in_number(n2) < 0){
    std::cout << "invalid first number" << std::endl;
    return -1;
  }

  int gcd_result = std::gcd(n1, n2);
  if (gcd_result > 1)
    std::cout << "gcd_result : " << gcd_result << std::endl;
  else
    std::cout << "not exist gcd_result" << std::endl;
  return 0;
}
#endif
