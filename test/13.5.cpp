#include <iostream>
#include <string>
using namespace std;

int Add(int a, int b)
{
  cout << "-----" << endl;
  return a + b;
}

template <typename T>
T Add(T a, T b)
{
  cout << "++++++" << endl;
  return a + b;
}

template <typename T>
T Add(T a, T b, T c)
{
  cout << "..............." << endl;
  return Add(Add(a, b), c);
}

int main()
{
  int a = 2;
  int b = 3;
  cout << Add(a, b) << endl;

  cout << Add<>(a, b) << endl;
  cout << Add(5, 6) << endl;
  cout << Add(5, 6, 7) << endl;

  cout << Add('a', 10) << endl;

  return 0;
}