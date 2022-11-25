//公有继承

//编码会影响输出
#include <iostream>
#include <string>

using namespace std;

class Car
{
public:
    void show()
    {
        cout << "name:\t" << name << endl;
        cout << "sell:\t" << sell << endl;
        cout << "color:\t" << color << endl;
    }

private:
    string name = " car ";
    int sell = 130000;
    string color = " black ";
};

class Car_1 : public Car
{
public:
    void show_1()
    {
        cout << "volume:\t" << volume << endl;
        cout << "addr:\t" << addr << endl;
    }

private:
    float volume = 1.5;
    char addr[50] = " shanghai ";
};

int main()
{
    Car_1 C;
    C.show();
    C.show_1();

    system("pause");

    return 0;
}