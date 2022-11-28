#include <iostream>
#include <fstream>
using namespace std;
int main()
{
  ofstream out;
  out.open("test.txt", ios::trunc);

  int i;
  char a = 'a';
  for (i = 1; i < 26; i++)
  {
    if (i < 10)
    {
      out << "0" << i << "\t" << a << "\n";
      a++;
    }
    else
    {
      out << i << "\t" << a << "\n";
      a++;
    }
  }
  out.close();
}