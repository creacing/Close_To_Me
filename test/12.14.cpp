#include <iostream>
#include <string>
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

    TDPoint operator++(int);

    friend TDPoint operator++(TDPoint &point, int);
    void showPoint();
};

TDPoint TDPoint::operator++(int)
{
    TDPoint point(*this);
    this->x++;
    this->y++;
    this->z++;

    return point;
}
TDPoint operator++(TDPoint &point, int)
{
    TDPoint point1(point);
    point.x++;
    point.y++;
    point.z++;
    return point1;
}

void TDPoint::showPoint()
{
    cout << x << "---" << y << "---" << z << endl;
}

int main()
{
    TDPoint point(8, 8, 8);
    point = point.operator++(0);

    point.showPoint();
    point = operator++(point, 0);

    point.showPoint();

    return 0;
}