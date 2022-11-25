#include <iostream>
#include <string>

using namespace std;

class Test
{
public:
  int a;
  int b;

public:
  Test()
  {
    a = 0;
    b = 0;
    cout << "default" << endl;
  }

public:
  Test(int tempa, int tempb)
  {
    a = tempa;
    b = tempb;
  }

  bool operator<(const Test &myTest)
  {
    cout << "reload" << endl;
    return (a < myTest.a) && (b < myTest.b);
  }
};

int main()
{
  Test int1(1, 2);
  Test int2(2, 3);
  if (int1 < int2)
  {
    cout << "true" << endl;
  }
  else
  {
    cout << "false" << endl;
  }
  return 0;
}