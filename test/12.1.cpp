#include <iostream>
#include <string>
using namespace std;
class Mother{
  public:
    void face(){
      cout << "M F" << endl;
    }
    virtual void Say(){
      cout << "M S" << endl;
    }
};

class Son:public Mother{
  public:
    void Say(){
      cout << "S S" << endl;
    }
};
int main(){
  Son son;
  Mother *pMother = &son;
  pMother -> Say();
  return 0;
}