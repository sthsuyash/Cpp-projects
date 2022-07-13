#include <iostream>
using namespace std;

class A
{
private:
    int a;

public:
    A() { a = 0; }
    A(int a)
    {
        this->a = a;
    }
    friend class B;
};

class B
{
private:
    int b;

public:
    B() { b = 0; }
    B(int b)
    {
        this->b = b;
    }
    void display(A a1)
    {
        cout << "A : " << a1.a << endl;
        cout << "B : " << b << endl;
    }
};

int main()
{
    A a(5);
    B b(10);
    b.display(a);
    return 0;
}