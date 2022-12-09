#include <iostream>
#include <string>
using namespace std;

class CBase
{
    string name;
    int age;

public:
    string getName()
    {
        return name;
    }
    int getAge()
    {
        return age;
    }

protected:
    void setName(string s)
    {
        name = s;
    }
    void setAge(int i)
    {
        age = i;
    }
};

class CDerive : protected CBase
{
public:
    void setBase(string s, int i)
    {
        setName(s);
        setAge(i);
    }

    string getBaseName()
    {
        return getName();
    }
    int getBaseAge()
    {
        return getAge();
    }
};

int main()
{
    CDerive d;
    d.setBase('xx', 11);

    cout << d.getBaseName() << "   " << d.getBaseAge() << endl;
}