#include <iostream>
#include <set>
using namespace std;
int main()
{
  set<int> set1;
  for (int i = 0; i < 10; ++i)
  {
    set1.insert(i);
  }
  set1.begin();
  set1.end();

  for (set<int>::iterator p = set1.begin(); p != set1.end(); ++p)
  {
    cout << *p;
  }
  cout << endl;
  if (set1.insert(3).second)
  {
    cout << "success" << endl;
  }
  else
  {
    cout << "failed" << endl;
  }

  int a[] = {4, 1, 1, 1, 1, 1, 0, 5, 1, 0};
  multiset<int> A;
  A.insert(set1.begin(), set1.end());
  A.insert(a, a + 10);
  cout << endl;

  for (multiset<int>::iterator p = A.begin(); p != A.end(); ++p)
  {
    cout << *p;
  }
  cout << endl;

  return 0;
}