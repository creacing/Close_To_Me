#include <iostream>
#include <string>
using namespace std;
class People{
public: 
People(string n,string s,float h){
  name = n;
  sex = s;
  height = h; 
}
protected:
  string name;
  string sex;
  float height;
};

class Student:public People{
  public:
    Student(string n,string s,float h,int a,string id):People(n,s,h){
      age = a;
      addr = id;
    }
    void show(){
      cout << "name" << name <<endl;
      cout << "sex" << sex <<endl;
      cout << "height" << height <<endl;
      cout << "age" << age <<endl;
      cout << "addr" << addr <<endl;

      cout << "end" << endl;

    }

  private:
    int age;
    string addr;
};

int main(){
  Student s1("demo","demo",123,11,"123");

  s1.show();

  system("pause");
}