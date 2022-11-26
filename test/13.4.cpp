#include <iostream>
using namespace std;

template <typename T>

T max(T a, T b)
{

  return (a > b) ? a : b;
}

int main()
{
  cout << ::max(3, 5) << endl;
  cout << ::max(2.5, 3.1) << endl;
  cout << ::max('x', 'y') << endl;

  return 0;
}