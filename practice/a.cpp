#include <iostream>
#include <string>
using namespace std;

class Employee
{
private:
    int acc_no;
    string name;
    static int balance, count;

public:
    Employee() { count++; }
    void setter()
    {
        cout << "Enter your account number: ";
        cin >> acc_no;
        cout << "Enter your name: ";
        cin >> name;
    }
    void getter()
    {
        cout << "Account Number: " << acc_no << endl
             << "Name: " << name << endl;
    }
    static void setMinBalance()
    {
        cout << "Enter min balance: ";
        cin >> balance;
    }
    static void getMinBalance()
    {
        cout << "Min Balance: " << balance << endl;
    }
    static int countGetter()
    {
        return count;
    }
};

int Employee::balance = 0;
int Employee::count = 0;

int main()
{
    Employee emp[2];
    Employee::setMinBalance();
    for (int i = 0; i < 2; i++)
    {
        emp[i].setter();
    }

    Employee::getMinBalance();
    cout << "Count: " << Employee::countGetter() << endl;
    for (int i = 0; i < 2; i++)
    {
        emp[i].getter();
    }
    return 0;
}