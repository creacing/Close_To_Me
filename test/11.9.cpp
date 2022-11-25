#include <iostream>
#include <string>
using namespace std;
class A{
  public:
    static int a;
    static int b;
    static int c;
};

int A::a = 100;
int A::b = 200;
int A::c = 300;
class B:public A{
  public:
    void out(){
      cout << a << endl << b <<endl << c <<endl;
    }
    void plus(){
      ++a;
      ++b;
      ++c;
    }
};

int main(){
  B bb;
  bb.plus();
  bb.out();
  cout <<A::a<<endl<<A::b<<endl<<A::c<<endl;
}
 
