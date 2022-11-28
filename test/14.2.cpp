#include <iostream>
using namespace std;
template <class T>
class Compare
{
private:
  T x, y;

public:
  Compare(T a, T b)
  {
    x = a;
    y = b;
  }
  T max();
  // T max()
  // {
  //   return (x > y) ? x : y;
  // }
  T min()
  {
    return (x < y) ? x : y;
  }
};
template <class T>
T Compare<T>::max()
{
  return (x > y) ? x : y;
}

int main()
{
  Compare<int> cmp1(3, 7);
  cout << cmp1.max() << endl;
  cout << cmp1.min() << endl;

  Compare<double> cmp2(51.25, 51.33);

  cout << cmp2.max() << endl;
  cout << cmp2.min() << endl;
}