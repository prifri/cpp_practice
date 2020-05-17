#include <iostream>
#include "../include/comm.h"
#include <cstring>

using namespace std;

class Date{
  protected:
    int year, month, day;
  public:
    Date(int y, int m, int d) : year(y), month(m), day(d)
  {
  }
    void OutDate(void)
    {
      printf("%d/%d/%d", year, month, day);
    }
};

class Product{
  private:
    char Name[64];
    char Company[32];
    Date ValidTo;
    int Price;
  public:
    Product(const char *aN, const char *aC, int y, int m, int d, int aP)
      : ValidTo(y, m, d), Price(aP)
    {
      strncpy(Name, aN, 63);
      Name[63] = '\0';
      strncpy(Company, aC, 31);
      Company[31] = '\0';
    }

    void OutProduct(void)
    {
      printf("Nmae : %s\n", Name);
      printf("Company : %s\n", Company);
      printf("valid date : ");
      ValidTo.OutDate();
      puts("");
      printf("price : %d\n", Price);
    }
};

int main(void)
{
  Product S("A", "B", 2009, 8, 5, 9000);
  S.OutProduct();
  return 0;
}
