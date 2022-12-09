#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int a = 33;
  int *b = &a;
  cout << a << *b << (a == *b) << endl;
}
