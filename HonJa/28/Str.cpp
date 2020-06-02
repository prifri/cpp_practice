#include <iostream>
#include "../include/comm.h"
#include <cstring>
#include <cstdarg>

using namespace std;

class Str{
  friend ostream &operator <<(ostream &c, const Str &s);
  friend const Str operator +(const char *ptr, const Str &s);
  friend bool operator ==(const char *ptr, Str &s);
  friend bool operator !=(const char *ptr, Str &s);
  friend bool operator >(const char *ptr, Str &s);
  friend bool operator <(const char *ptr, Str &s);
  friend bool operator >=(const char *ptr, Str &s);
  friend bool operator <=(const char *ptr, Str &s);

  protected:
  char *buf;
  int size;

  public:
  Str();
  Str(const char *ptr);
  Str(const Str &Other);
  explicit Str(int num);
  virtual ~Str(void);

  int length(void) const
  {
    return size-1;
  }

  Str &operator = (const Str &Other);
  Str &operator += (Str &Other);
  Str &operator += (const char *ptr);
  char &operator [](int idx)
  {
    return buf[idx];
  }
  const char &operator [](int idx) const
  {
    return buf[idx];
  }
  operator const char *()
  {
    return (const char *)buf;
  }
  operator int()
  {
    return atoi(buf);
  }
  const Str operator +(Str &Other) const;
  const Str operator +(const char *ptr)  const;
  bool operator == (Str &Other)
  {
    return strcmp(buf, Other.buf) == 0;
  }
  bool operator == (const char *ptr)
  {
    return strcmp(buf, ptr) == 0;
  }
  bool operator != (Str &Other)
  {
    return strcmp(buf, Other.buf) != 0;
  }
  bool operator != (const char *ptr)
  {
    return strcmp(buf, ptr) != 0;
  }
  bool operator > (Str &Other)
  {
    return strcmp(buf, Other.buf) > 0;
  }
  bool operator > (const char *ptr)
  {
    return strcmp(buf, ptr) > 0;
  }
  bool operator < (Str &Other)
  {
    return strcmp(buf, Other.buf) < 0;
  }
  bool operator < (const char *ptr)
  {
    return strcmp(buf, ptr) < 0;
  }
  bool operator >= (Str &Other)
  {
    return strcmp(buf, Other.buf) >= 0;
  }
  bool operator >= (const char *ptr)
  {
    return strcmp(buf, ptr) >= 0;
  }
  bool operator <= (Str &Other)
  {
    return strcmp(buf, Other.buf) <= 0;
  }
  bool operator <= (const char *ptr)
  {
    return strcmp(buf, ptr) <= 0;
  }
  void Format(const char *fmt, ...);
};

Str :: Str()
{
  size = 1;
  buf = new char[size];
  buf[0] = 0;
}

Str :: Str(const char *ptr)
{
  size = strlen(ptr)+1;
  buf = new char[size];
  strcpy(buf, ptr);
}

Str :: Str(const Str &Other)
{
  size = Other.size;
  buf = new char[size];
  strcpy(buf, Other.buf);
}

Str :: Str(int num)
{
  buf = new char[33];
  int idx;

  if (num < 0){
    buf[0] = '-';
    idx = 1;
  }
  else
    idx = 0;

  if (num){
    while (num){
      buf[idx++] = num%10 + '0';
      num /= 10;
    }
  }
  else{
    buf[idx++] = '0';
  }

  buf[idx] = '\0';
  size = idx+1;
}

Str :: ~Str(void)
{
  delete [] buf;
}

Str &Str::operator =(const Str &Other)
{
  if (this != &Other){
    delete [] buf;
    size = Other.size;
    buf = new char[size];
    strcpy(buf, Other.buf);
  }
  return *this;
}

Str &Str :: operator +=(Str &Other)
{
  char *old;
  int old_size = size;

  old = buf;
  size += Other.length();
  buf = new char[size];
  strcpy(buf, old);
  strcpy(&buf[old_size], Other.buf);
  delete [] old;

  return *this;
}

Str &Str :: operator +=(const char *ptr)
{
  char *old;
  int old_size = size;

  old = buf;
  size += strlen(ptr);
  buf = new char[size];
  strcpy(buf, old);
  strcpy(&buf[old_size], ptr);
  delete [] old;

  return *this;
}

const Str Str :: operator +(Str &Other) const
{
  Str T;

  delete [] T.buf;
  T.size = length() + Other.length() + 1;
  T.buf = new char[T.size];
  strcpy(T.buf, buf);
  strcpy(&T.buf[length()], Other.buf);
  return T;
}

const Str Str :: operator +(const char *ptr)  const
{
  Str T;

  delete [] T.buf;
  T.size = length() + strlen(ptr) + 1;
  T.buf = new char[T.size];
  strcpy(T.buf, buf);
  strcpy(&T.buf[length()], ptr);
  return T;
}
ostream &operator << (ostream &c, const Str &S)
{
  c << S.buf;
  return c;
}

const Str operator +(const char *ptr, Str &s)
{
  return Str(ptr) + s;
}

bool operator == (const char *ptr, Str &s)
{
  return strcmp(ptr, s.buf) == 0;
}

bool operator != (const char *ptr, Str &s)
{
  return strcmp(ptr, s.buf) != 0;
}

bool operator > (const char *ptr, Str &s)
{
  return strcmp(ptr, s.buf) > 0;
}

bool operator < (const char *ptr, Str &s)
{
  return strcmp(ptr, s.buf) < 0;
}

bool operator >= (const char *ptr, Str &s)
{
  return strcmp(ptr, s.buf) >= 0;
}


bool operator <= (const char *ptr, Str &s)
{
  return strcmp(ptr, s.buf) <= 0;
}

void Str :: Format(const char *fmt, ...)
{
  int size = 1024;
  char temp[size];
  va_list marker;

  va_start(marker, fmt);
  if (vsnprintf(temp, size, fmt, marker) != size){
    *this = Str(temp);
  }
  else {
    size += 1024;
    char *p = new char[size];
    while (size == vsnprintf(p, size, fmt, marker)){
      delete [] p;
      size += 1024;
    }
    *this = Str(p);
    delete [] p;
  }
  va_end(marker);
}

int main(void)
{
  Str s="125";
  int k;
  k = (int)s + 123;

  cout << "s(125) + 123 = " << k << endl;
  Str s1("string");
  Str s2(s1);
  Str s3;
  s3 = s1;

  cout << "s1=" << s1 << ".s2=" << s2 << ".s3=" << s3 << endl;
  cout << "length=" << s1 << endl;

  Str s4(1234);
  cout << "s4=" << s4 << endl;
  int num = int(s4) + 1;
  cout << "num=" << num << endl;

  Str s5 = "first";
  Str s6 = "Second";
  cout << s5 + s6 << endl;
  cout << s6 + "Third" << endl;
  cout << "Zero+ + s5" << endl;
  cout << "s1 is "+s1+" and s5 is "+s5+"." << endl;
  s5 += s6;

  cout << "s5 + s6 is " << s5 << "." << endl;
  s5 += "Concatination";

  cout << "s5 append string is " << s5 << "." << endl;

  if (s1 == s2) {
    cout << "string is same" << endl;
  }
  else {
    cout << "string is not same" << endl;
  }

  Str s7;
  s7 = "const string";
  cout << s6 << endl;
  char str[128];
  strcpy(str, s7);
  cout << str << endl;

  Str s8("index");
  cout << "s8[2]=" << s8[2] << endl;
  s8[2] = 'k';
  cout << "s8[2]=" << s8[2] << endl;

  Str sf;
  int i = 9876;
  double d = 1.234567;
  sf.Format("format make. int = %d, read = %.2f", i, d);
  cout  << sf << endl;
  return 0;
}
