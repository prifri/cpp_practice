#include <iostream>
#include <numeric>

uint64_t lcm(int a, int b)
{
    return a * b / std::gcd(a, b);
}

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

  uint64_t lcm_result = std::gcd(n1, n2)*lcm(n1, n2);
  std::cout << "lcm_result : " << lcm_result << std::endl;
  return 0;
}
