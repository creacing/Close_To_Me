#include <iostream>
#include <string>
using namespace std;

class CBase{
  public:
    virtual int func() const{
      cout << "-------" << endl;
      return 100;
    }
};

class CDerive:public CBase{
  public:
    int func() const{
      cout << "+++++++" << endl;

      return 200;
    }
};

int main(){
  CDerive obj1;
  CBase *p1 = &obj1;
  CBase &p2 = obj1;
  CBase obj2;

  obj1.func();
  p1 -> func();
  p2.func();
  obj2.func();
}