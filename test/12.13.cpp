#include <iostream>
using namespace std;

class TDPoint
{
private:
  int x;
  int y;
  int z;

public:
  TDPoint(int x = 0, int y = 0, int z = 0)
  {
    this->x = x;
    this->y = y;
    this->z = z;
  }
  TDPoint operator++();

  friend TDPoint operator++(TDPoint &point);
  void showPoint();
};

TDPoint TDPoint::operator++()
{
  ++this->x;
  ++this->y;
  ++this->z;

  return *this;
}

TDPoint operator++(TDPoint &point)
{
  ++point.x;
  ++point.y;
  ++point.z;
  return point;
}

void TDPoint::showPoint()
{
  cout << x << "---" << y << "---" << z << endl;
}
int main()
{
  TDPoint point(8, 8, 8);
  point.operator++();
  point.showPoint();
  operator++(point);
  point.showPoint();

  return 0;
}