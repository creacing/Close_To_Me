#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int CountLines(const char *filename)
{
  ifstream ReadFile;
  int n = 0;
  char line[512];
  string temp;
  ReadFile.open(filename, ios::in);
  cout << ReadFile.fail() << endl;
  if (ReadFile.fail())
  {
    ReadFile.close();
    return 0;
  }
  else
  {
    while (getline(ReadFile, temp))
    {
      cout << temp << endl;
      n++;
    }
    ReadFile.close();
    return n;
  }
}

int main()
{
  cout << CountLines("test.txt") << endl;

  // cin.get();
}