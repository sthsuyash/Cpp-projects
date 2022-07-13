#include <iostream>
#include <string>
using namespace std;

class lecture
{
protected:
    int ID;
    string name;

public:
    void readData(int ID, string name)
    {
        this->ID = ID;
        this->name = name;
    }
    void printData()
    {
        cout << "ID = " << ID << endl
             << "Name = " << name << endl;
    }
};

class partTime : public lecture
{
private:
    float payperhr;

public:
    void readData(int ID, string name, float payperhr)
    {
        this->payperhr = payperhr;
        lecture::readData(ID, name);
    }
    void printData()
    {
        lecture::printData();
        cout << "Pay per hour = " << payperhr << endl;
    }
};

class fullTime : public lecture
{
private:
    float paypermonth;

public:
    void readData(int ID, string name, float paypermonth)
    {
        this->paypermonth = paypermonth;
        lecture::readData(ID, name);
    }
    void printData()
    {
        lecture::printData();
        cout << "Pay per hour = " << paypermonth << endl;
    }
};

int main()
{
    partTime pT;
    fullTime fT;
    int ID;
    string name;
    float pay;
    cout << "For part time: " << endl;
    cout << "Enter ID: ";
    cin >> ID;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter pay: ";
    cin >> pay;
    pT.readData(ID, name, pay);
    cout << endl;
    cout << "For full time: " << endl;
    cout << "Enter ID: ";
    cin >> ID;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter pay: ";
    cin >> pay;
    fT.readData(ID, name, pay);
    cout << endl;
    cout << "Reading from Part Time:" << endl;
    pT.printData();
    cout << "--------------------------------" << endl;
    cout << "Reading from Full Time:" << endl;
    fT.printData();
    return 0;
}