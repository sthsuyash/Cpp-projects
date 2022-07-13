#include <iostream>
using namespace std;

class complex
{
private:
    int real, imag;

public:
    complex(int r = 0, int i = 0)
    {
        real = r;
        imag = i;
    }
    friend ostream &operator<<(ostream &out, const complex &c);
    friend istream &operator>>(istream &in, complex &c);
};

ostream &operator<<(ostream &out, const complex &c)
{
    out << c.real << "+" << c.imag << "i" << endl;
    return out;
}

istream &operator>>(istream &in, complex &c)
{
    cout << "Enter real part: ";
    in >> c.real;
    cout << "Enter imaginary part: ";
    in >> c.imag;
    return in;
}

int main()
{
    complex c1;
    cin >> c1;
    cout << c1;
    return 0;
}