#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  char buffer[256];
  fstream in;
  in.open("test.txt", ios::in);

  while (!in.eof())
  {
    in.getline(buffer, 256, '\n');

    cout << buffer << endl;
  }

  in.close();
  cin.get();
}