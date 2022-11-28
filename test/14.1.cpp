#include <iostream>
using namespace std;

class A
{
public:
  A(int i)
  {
    m_A = i;
  }
  ~A()
  {
  }
  static void print()
  {
    cout << "A" << endl;
  }

  friend class B;

protected:
  int m_A;
};

class B
{
public:
  B(int i)
  {
    m_B = i;
  }
  static void print()
  {
    cout << "B" << endl;
  }

  void show(B b)
  {
    b.a->m_A = 10;
    b.m_B = 2;
  }

private:
  A *a;
  int m_B;
};

template <class T1, class T2>
class CTestTemplate
{
private:
  int m_number;

public:
  CTestTemplate(T1 t)
  {
    m_number = t;
  }
  void print()
  {
    T2::print();
    cout << m_number << endl;
  }
};

int main(int argc, char *argv[])
{
  CTestTemplate<int, B> testtem(3);
  testtem.print();
}