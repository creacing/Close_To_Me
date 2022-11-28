#include <iostream>
#include <cstring>
using namespace std;
template <typename T>
bool fun(T t1, T t2)
{
  return t1 == t2;
}

template <>
bool fun(char *t1, char *t2)
{
  return strcmp(t1, t2) == 0;
}

int main()
{

  char str1[] = "hello";
  char str2[] = "hello";
  cout << fun(1, 1) << endl;
  cout << fun(str1, str2) << endl;

  return 0;
}