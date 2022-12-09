#include <iostream>
#include <string>
//基类构造函数的作用
using namespace std;

class Animal
{

public:
    void eat()
    {
        cout << "animal eat" << endl;
    }
    void sleep()
    {
        cout << "animal sleep" << endl;
    }
    void breathe()
    {
        cout << "anima breathe" << endl;
    }
    Animal()
    {
        cout << "animal construct" << endl;
    }
};
class Fish : public Animal
{
public:
    Fish()
    {
        cout << "fish construct" << endl;
    }
};

int main()
{
    Fish smallFish;

    return 0;
}
