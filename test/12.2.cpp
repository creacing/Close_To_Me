#include <iostream>
#include <string>
using namespace std;


class Student{
  public:
    Student(int,string,int);
    virtual void show();
  protected:
    int num;
    string name;
    int age;
};

Student::Student(int n,string nam, int a){
  num = n;
  name = nam;
  age = a;
}

void Student::show(){
  cout << num << name << age <<endl;
}

class Graduate:public Student{
  public:
    Graduate(int , string,int ,float);
    void show();
  private:
    float score;
};

void Graduate::show(){
  cout << num <<name<<age<<score<<endl;
}

Graduate::Graduate(int n,string nam,int a,float s):Student(n,nam,a),score(s){

}
int main(){
  Student stud1(1,"xx",11);

  Graduate grad1(2,"ee",22,33.3);

  Student *pt = &stud1;

  pt-> show();
  pt = &grad1;
  pt->show();
  return 0;
}