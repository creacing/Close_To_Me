#include <iostream>
#include <string>
using namespace std;

class Complex
{
private:
  double real;
  double imag;

public:
  Complex(double real = 0, double imag = 0)
  {
    this->real = real;
    this->imag = imag;
  }

  friend ostream &operator<<(ostream &o, Complex &com);

  friend istream &operator>>(istream &i, Complex &com);
};

ostream &operator<<(ostream &o, Complex &com)
{
  cout << "输入的复数";
  o << com.real;

  if (com.imag > 0)
  {
    o << "+";
  }

  if (com.imag != 0)
  {
    o << com.imag << "i" << endl;
  }
  return o;
}

istream &operator>>(istream &i, Complex &com)
{
  cout << "输入一个复数";
  cout << "real(实数):";
  i >> com.real;
  cout << "imag(虚数):";
  i >> com.imag;
  return i;
}

int main()
{
  Complex com;
  cin >> com;
  cout << com;

  return 0;
}