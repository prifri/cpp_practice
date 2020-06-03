#include <iostream>

uint64_t cal_func(int base, int limit)
{
  uint64_t sum = 0;

  for (int i=1 ;; i++){
    int cal = base*i;
    if (cal > limit)
      return sum;
    sum += cal;
  }
}

int main(void)
{
  int n;

  std::cout << "in number : ";
  std::cin >> n;

  if (n <= 0){
    std::cout << "number is invalid" << std::endl;
    return -1;
  }

  std::cout
      << "result : "
      << cal_func(3, n) + cal_func(5, n) - cal_func(15, n)
      << std::endl;
  return 0;
}
