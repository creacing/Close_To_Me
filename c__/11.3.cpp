#include <iostream>
#include <string>
using namespace std;

class Document
{
public:
    Document(string D_newName);
    void getName();
    string D_Name;
};

Document::Document(string D_newName)
{
    D_Name = D_newName;
}
void Document::getName()
{
    cout << "Document 类的名称是：" << D_Name << endl;
}

class Book : public Document
{
public:
    Book(string D_newName, string newName);

    void getName();
    void setPageCount(int newPageCount);
    void getPageCount();

private:
    int PageCount;
    string Name;
};
// Document = D_newName
Book::Book(string D_newName, string newName) : Document(D_newName)
{
}
