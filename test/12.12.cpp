#include <iostream>
#include <cstring>
using namespace std;

class Internet
{
public:
  Internet(const char *name, const char *url)
  {
    Internet::name = new char[strlen(name) + 1];
    Internet::url = new char[strlen(url) + 1];
    if (name)
    {
      strcpy_s(Internet::name, strlen(name) + 1, name);
    }
    if (url)
    {
      strcpy_s(Internet::url, strlen(url) + 1, url);
    }
  }
  Internet(Internet &temp)
  {
    Internet::name = new char[strlen(temp.name) + 1];
    Internet::url = new char[strlen(temp.url) + 1];
    if (name)
    {
      strcpy_s(Internet::name, strlen(temp.name) + 1, temp.name);
    }
    if (url)
    {
      strcpy_s(Internet::url, strlen(temp.url) + 1, temp.url);
    }
  }
  ~Internet()
  {
    delete[] name;
    delete[] url;
  }

  Internet &operator=(Internet &temp)
  {
    delete[] this->name;
    delete[] this->url;
    this->name = new char[strlen(temp.name) + 1];
    this->url = new char[strlen(temp.url) + 1];

    if (this->name)
    {
      strcpy_s(this->name, strlen(temp.name) + 1, temp.name);
    }
    if (this->url)
    {
      strcpy_s(this->url, strlen(temp.url) + 1, temp.url);
    }
    return *this;
  }

public:
  char *name;
  char *url;
};

int main()
{
  Internet a("qq", "ww");
  Internet b = a;

  cout << b.name << b.url << endl;

  Internet c("ee", "rr");
  b = c;

  cout << b.name << b.url << endl;
}