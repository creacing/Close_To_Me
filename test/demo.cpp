#include <iostream>
#include <string>
using namespace std;

int main()
{
  const string a = "please sit";
  for (auto b : a)
  {
    cout << b << endl;
  }
}