#include <iostream>
#include <string>

using namespace std;

template <class T>

T min(T x, T y)
{
  return (x < y) ? x : y;
}

int main()
{
  int n1 = 18, n2 = 26;
  double d1 = 5.6, d2 = 7.8;
  cout << "min int" << ::min(n1, n2) << endl;
  cout << "min double" << ::min(d1, d2) << endl;
}