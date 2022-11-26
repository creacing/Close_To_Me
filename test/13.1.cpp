#include <iostream>
using namespace std;
template <typename T>

void swap(T &x, T &y)
{
  T temp;
  temp = x;
  x = y;
  y = temp;

  cout << x << "---" << y << endl;
}

int main()
{
  int a = 10;
  int b = 20;
  ::swap(a, b);
  float m = 2.5;
  float n = 3.5;
  ::swap(m, n);
  ::swap<float>(m, n);
  return 0;
}