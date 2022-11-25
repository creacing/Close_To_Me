#include <iostream>
#include <string>
using namespace std;

class Complex{
  public:
    Complex(){
      real = 0;
      imag = 0;

    }
    Complex(double a,double b){
      real = a;
      imag = b;
    }

    friend Complex operator +(Complex &c1,Complex &c2);
    void show();
  private:
    double real;
    double imag;
};
Complex operator+(Complex &c1,Complex &c2){
  return Complex(c1.real+c2.real,c1.imag+c2.imag);
}

void Complex::show(){
  cout << real << "," << imag << endl;
}

int main(){
  Complex c1(50,13),c2(80,17),c3;
  c3 = c1 + c2;

  c1.show();
  c2.show();
  c3.show();
}