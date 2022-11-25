#include <iostream>
#include <string>
using namespace std;

class Base{
  public:
   virtual void fun(){
    cout << "------" << endl;
   }
};
class Derive:public Base{
  public:
    void fun(){
      cout << "+++++++" << endl;
    }
};

int main(){
  Derive d;
  Base *p = &d;
  p->fun();
  return 0;
}