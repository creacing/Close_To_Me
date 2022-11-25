#include <iostream>

using namespace std;
class Time
{
public:
    Time(int h = 0, int m = 0, int s = 0);

    friend istream &operator>>(istream &, Time &);

    friend ostream &operator<<(ostream &, Time &);

private:
    int hour, minute, second;
};

Time::Time(int h, int m, int s)
{
    hour = h;
    minute = m;
    second = s;
}
istream &operator>>(istream &, Time &temp)
{
    return cin >> temp.hour >> temp.minute >> temp.second;
}

ostream &operator<<(ostream &, Time &temp)
{
    cout << temp.hour << ":" << temp.minute << ":" << temp.second;
}

int main()
{
    Time myTime(12, 48, 35);
    cout << myTime;
    return 0;
}