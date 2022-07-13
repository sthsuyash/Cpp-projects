#include <iostream>
#include <string>
using namespace std;

class author
{
protected:
    string name, qualifications;

public:
    void getdata()
    {
        cout << "Enter name of author: ";
        cin >> name;
        cout << "Enter qualification: ";
        cin >> qualifications;
    }

    void putdata()
    {
        cout << "Author: " << name << endl
             << "Qualification: " << qualifications << endl;
    }
};

class publication
{
protected:
    string pname;

public:
    void getdata()
    {
        cout << "Enter publication: ";
        cin >> pname;
    }

    void putdata()
    {
        cout << "Publication name: " << pname << endl;
    }
};

class book : public author, public publication
{
private:
    float price;
    string title;

public:
    void getdata()
    {
        author::getdata();
        publication::getdata();
        cout << "Enter title: ";
        cin >> title;
        cout << "Enter price: ";
        cin >> price;
    }

    void putdata()
    {
        author::putdata();
        publication::putdata();
        cout << "Title of book: " << title << endl;
        cout << "Price: " << price << endl;
    }
};

int main()
{
    book book1;
    book1.getdata();
    book1.putdata();
    return 0;
}