#include <iostream>
using namespace std;

struct Person
{
  const char *name;
  int age;
};

// 定义函数模板
template <typename T>
constexpr T dispaly(T t)
{
  return t;
}

int main()
{
  struct Person p
  {
    "luffy", 19
  };
  //普通函数
  struct Person ret = dispaly(p);
  cout << "luffy's name: " << ret.name << ", age: " << ret.age << endl;

  //常量表达式函数
  constexpr int ret1 = dispaly(250);
  cout << ret1 << endl;

  constexpr struct Person p1
  {
    "luffy", 19
  };
  constexpr struct Person p2 = dispaly(p1);
  cout << "luffy's name: " << p2.name << ", age: " << p2.age << endl;
  return 0;
}
