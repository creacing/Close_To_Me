#include <iostream>
#include <string>
using namespace std;

class MyClass_A{
  public:
    MyClass_A(int a,int b);
    ~MyClass_A();
  protected:
    int m_a;
    int m_b;
};

MyClass_A::MyClass_A(int a,int b):m_a(a),m_b(b){
  cout << "A construct" << endl;
}

MyClass_A::~MyClass_A(){
  cout << "A destory" << endl;
}

class MyClass_B{
  public:
    MyClass_B(int c,int d);
    ~MyClass_B();
  protected:
    int m_c;
    int m_d;
};

MyClass_B::MyClass_B(int c,int d):m_c(c),m_d(d){
  cout << "B construct" << endl;
}
MyClass_B::~MyClass_B(){
  cout << "B destory" << endl;
}

class MyClass_D:public MyClass_A,public MyClass_B{
  public:
    MyClass_D(int a,int b,int c,int d,int e);
    ~MyClass_D();
  public: 
    void show();
  private:
    int m_e;
};

MyClass_D::MyClass_D(int a,int b,int c,int d,int e):MyClass_A(a,b),MyClass_B(c,d),m_e(e){
  cout << "export construct" << endl;
}

MyClass_D::~MyClass_D(){
  cout << "export destory" << endl;
}

void MyClass_D::show(){
  cout << m_a << m_b << m_c << m_d << m_e << endl;
}

int main(){
  MyClass_D c(1,2,3,4,5);
  c.show();
  return 0;
}

