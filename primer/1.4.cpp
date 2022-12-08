#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
  string s("something");
  if (s.begin() != s.end())
  {
    auto it = s.begin();
    *it = toupper(*it);
  }

  cout << s << endl;
}
