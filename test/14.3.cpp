#include <iostream>
using namespace std;

template <typename T>
class Pair
{
  T value1, value2;

public:
  Pair(T first, T second)
  {
    value1 = first;
    value2 = second;
  }
  T module()
  {
    return 0;
  }
};
template <>
class Pair<int>
{
  int value1, value2;

public:
  Pair(int first, int second)
  {
    value1 = first;
    value2 = second;
  }
  int module();
};

int Pair<int>::module()
{
  return (value1 % value2);
}

int main()
{
  Pair<int> myints(10, 8);
  Pair<float> myfloats(10.0, 8.0);

  cout << myints.module() << endl;
  cout << myfloats.module() << endl;
  return 0;
}