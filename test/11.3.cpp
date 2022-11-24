#include <iostream>
#include <string>

using namespace std;

class Document {
 public:
  Document(string D_newName);
  void getName();
  string D_Name;
};

Document::Document(string D_newName){
  D_Name = D_newName;
}

void Document::getName(){
  cout<<"Document is:"<<D_Name<<endl;
}

class Book:public Document{
  public:
    Book(string D_newName,string newName);
    void getName();
    void setPageCount(int newPageCount);
    void getPageCount();
  private:
    int PageCount;
    string Name;
};
//调用基类的构造函数
Book::Book(string D_newName,string newName):Document(D_newName){
  Name = newName;
}

void Book::getName(){
  cout << "Book is:" << Name << endl;
}

void Book::setPageCount(int newPageCount){
  PageCount = newPageCount;
}
void Book::getPageCount(){
  cout << "PageCount is:" << PageCount <<endl;
}

int main(){
  Book x("demo1","demo2");
  x.getName();
  x.setPageCount(233);
  x.getPageCount();
}