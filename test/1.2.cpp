#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int a = 33;
  const int &b = a;

  cout << b << endl;

  a = 44;
  cout << b << endl;
}
