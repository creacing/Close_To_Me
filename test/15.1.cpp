#include <iostream>
#include <vector>
using namespace std;
int main()
{
  vector<int> a(10, 2);
  int i;
  for (i = 0; i < a.size(); i++)
  {
    cout << a[i];
  }

  cin >> a[2];
  cin >> a[5];
  cin >> a[8];

  cout << endl;
  for (i = 0; i < a.size(); i++)
  {
    cout << a[i];
  }
  cout << endl;

  return 0;
}