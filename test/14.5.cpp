#include <iostream>
#include <cstring>
using namespace std;
template <typename T>
class Comp
{
public:
  bool fun(T t1, T t2)
  {
    return t1 == t2;
  }
};

template <>
class Comp<char *>
{
public:
  bool fun(char *t1, char *t2)
  {
    return strcmp(t1, t2) == 0;
  }
};

int main()
{
  char str1[] = "hello";
  char str2[] = "hello";
  Comp<int> c1;
  Comp<char *> c2;
  cout << c1.fun(5, 1) << endl;
  cout << c2.fun(str1, str2) << endl;

  return 0;
}