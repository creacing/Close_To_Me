#include <iostream>
#include <string>

using namespace std;

class com
{
private:
  int real;
  int img;

public:
  com(int real = 0, int img = 0)
  {
    this->real = real;
    this->img = img;
  }
  com operator+(com x)
  {
    return com(this->real + x.real, this->img + x.img);
  }

  com operator+(int x)
  {
    return com(this->real + x, this->img + x);
  }
  friend com operator+(int x, com y);
  void show()
  {
    cout << real << "," << img << endl;
  }
};

com operator+(int x, com y)
{
  return com(x + y.real, y.img);
}

int main()
{
  com a, b(100, 200), c(200, 300);
  a = b + c;
  a.show();
  a = b + 30;
  a.show();
  a = 30 + c;
  a.show();
}