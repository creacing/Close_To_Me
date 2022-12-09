#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<unsigned int> scroll(11, 0);
  unsigned int grade;
  while (cin >> grade)
  {
    if (grade <= 100)
    {
      ++scroll[grade / 10];
      for (auto v : scroll)
      {
        cout << v;
      }

      cout << endl;
    }
  };
}
