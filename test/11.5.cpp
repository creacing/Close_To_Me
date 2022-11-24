#include <iostream>
#include <string>
using namespace std;

class CBase{
  string name;
  int age;
  public:
    string getName(){
      return name;
    }
    int getAge(){
      return age;
    }
  protected:
    void setName(string s){
      name = s;
    }

    void setAge(int i){
      age = i;
    }
} ;

class CDerive:public CBase{
  public:
    void setBase(string s,int i){
      setName(s);
      setAge(i);
    }
    
};

int main(){
  CDerive d;
  d.setBase("a",11);

  cout << d.getName() << "--" << d.getAge();

  return 0;
}