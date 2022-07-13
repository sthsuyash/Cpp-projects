#include <iostream>
using namespace std;

class Account
{
private:
    int acc_no, balance;

public:
    static int min_balance;

    Account() {}

    void setter()
    {
        cout << "Enter your account number: ";
        cin >> acc_no;
        cout << "Enter balance: ";
        cin >> balance;
    }

    void getter()
    {
        cout << "Account Number: " << acc_no << endl;
        cout << "Balance: " << balance << endl;
    }

    static void set_min_balance()
    {
        cout << "Enter min balance: ";
        cin >> min_balance;
    }

    static void get_min_balance()
    {
        cout << "Min Balance: " << min_balance << endl;
    }
};

int Account::min_balance = 0;

int main()
{
    int acc_no, balance;
    Account acc[5];

    Account::set_min_balance();
    cout << endl;

    for (size_t i = 0; i < 5; i++)
    {
        acc[i].setter();
        cout << endl;
    }

    cout << "--------------------------------" << endl;
    cout << "Successfully entered data" << endl;
    cout << "--------------------------------" << endl
         << endl;

    for (size_t i = 0; i < 5; i++)
    {
        acc[i].getter();
        Account::get_min_balance();
        cout << endl
             << endl;
    }
    return 0;
}