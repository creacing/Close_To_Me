#include <stdlib.h>
#include <fstream>
using namespace std;
int main()
{
  ofstream fout("test.txt");
  fout.put('h');
  fout.put('w');
  fout.close();
}