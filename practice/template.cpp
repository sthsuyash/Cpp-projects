#include <iostream>
using namespace std;

template <typename X>
class Parent
{
private:
    X a, b;

public:
    void setter(X a, X b)
    {
        this->a = a;
        this->b = b;
    }
    void getter()
    {
        cout << "A: " << a << endl
             << "B: " << b << endl;
    }
};

template <class X>
class Child : public Parent<X>
{
private:
    int x;

public:
    void setter(X a, X b, X x)
    {
        Parent<X>::setter(a, b);
        this->x = x;
    }
    void getter()
    {
        cout << "X: " << x << endl;
        Parent<X>::getter();
    }
};

int main()
{
    Child<int> child;
    child.setter(1, 2, 3);
    child.getter();
    return 0;
}