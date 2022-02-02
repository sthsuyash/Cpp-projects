#include <bits/stdc++.h>
using namespace std;

// global variable to goto main menu or exit
int main_choice;

// declaring required functions
void main_menu();
int enter_data();
void bin_to_dec();
void dec_to_bin();
void oct_to_dec();
void dec_to_oct();
void hex_to_dec();
void dec_to_hex();

// driver function
int main()
{
    system("color B");
    system("cls");
    // do
    // {
    main_menu();
    // re:
    //     cout << "\n\tPress 1 to goto main menu and 0 to exit: ";
    //     cin >> main_choice;
    //     if (main_choice == 1)
    //     {
    //         main_menu();
    //     }
    //     else if (main_choice == 0)
    //     {
    //         goto end;
    //     }
    //     else
    //     {
    //         cout << "\a\tEnter a valid option.\n";
    //         goto re;
    //     }

    // } while (main_choice > 1 || main_choice < 0);

end:
    // system("cls");
    cout << "\n\tEnd of program.\n"
         << endl;
    system("pause");

    return 0;
}

// main menu function which shows the options for user and calls the required functions
void main_menu()
{
    int choice;

    cout << "\n\n\tWhat calculation do you want to perform: \n";
    cout << "\t1. for Binary to Decimal conversion.\n";
    cout << "\t2. for Decimal to Binary conversion.\n";
    cout << "\t3. for Octal to Decimal conversion.\n";
    cout << "\t4. for Decimal to Octal conversion.\n";
    cout << "\t5. for HexaDecimal to Decimal conversion.\n";
    cout << "\t6. for Decimal to HexaDecimal conversion.\n";

    cout << "\n\tChoose one option: ";
    cin >> choice;

    switch (choice)
    {

    case 1:
        system("cls");
        bin_to_dec();
        break;

    case 2:
        system("cls");
        dec_to_bin();
        break;

    case 3:
        system("cls");
        oct_to_dec();
        break;

    case 4:
        system("cls");
        dec_to_oct();
        break;

    case 5:
        system("cls");
        hex_to_dec();
        break;

    case 6:
        system("cls");
        dec_to_hex();
        break;

    default:
        system("cls");
        cout << "\a\nEnter a valid choice." << endl;
        main_menu();
        break;
    }
    return;
}

// creating namespace for including function for entering number input for binary, decimal and octal
namespace entry_num
{
    int enter_data()
    {
        system("cls");
        int num;
        cout << "\n\tEnter a number: ";
        cin >> num;
        return num;
    }
}

// creating namespace for including function for entering string input for hexadecimal under same funtion name
namespace entry_char
{
    string enter_data()
    {
        system("cls");
        string data;
        cout << "\n\tInput: ";
        cin >> data;
        return data;
    }
}

void bin_to_dec()
{
    int bin = entry_num::enter_data();
    int dec = 0, base = 1, qn;

    while (bin > 0)
    {
        int lastDigit = bin % 10;
        dec += lastDigit * base;
        base *= 2;
        bin /= 10;
    }
    cout << "\n\tBinary: " << qn << endl
         << "\tDecimal: " << dec << endl;
}

void dec_to_bin()
{
    int dec = entry_num::enter_data();
    int qn = dec, base = 1;
    long long bin = 0;

    while (dec > 0)
    {
        int ans = dec % 2;
        bin += ans * base;
        dec /= 2;
        base *= 10;
    }

    cout << "\n\tDecimal: " << qn << endl
         << "\tBinary: " << bin << endl;
}

void oct_to_dec()
{
    int oct = entry_num::enter_data();
    int qn = oct, base = 1, dec = 0;

    while (oct > 0)
    {
        int lastDigit = oct % 10;
        dec += lastDigit * base;
        oct /= 10;
        base *= 8;
    }

    cout << "\n\tOctal: " << qn << endl
         << "\tDecimal: " << dec << endl;
}

void dec_to_oct()
{
    int dec = entry_num::enter_data();
    int qn = dec, oct = 0, base = 1;

    while (dec > 0)
    {
        int ans = dec % 8;
        oct += ans * base;
        dec /= 8;
        base *= 10;
    }

    cout << "\n\tDecimal: " << qn << endl
         << "\tOctal: " << oct << endl;
}

void hex_to_dec()
{
    string hex = entry_char::enter_data();
    string ans = hex;
    int dec = 0, i = 1, size = hex.size();

    for (int j = size - 1; j >= 0; j--)
    {
        if (hex[j] >= '0' && hex[j] <= '9')
        {
            dec += (hex[j] - '0') * i;
        }
        else if (hex[j] >= 'A' && hex[j] <= 'F')
        {
            dec += (hex[j] - 'A' + 10) * i;
        }
        i *= 16;
    }

    cout << "\n\tHexadecimal: " << ans << endl
         << "\tDecimal: " << dec << endl;
}

void dec_to_hex()
{
    int dec = entry_num::enter_data();
    int ans = dec, base = 1;
    string hex = "";

    while (base <= dec)

        base *= 16;
    base /= 16;

    while (base > 0)
    {
        int lastDigit = dec / base;
        dec -= lastDigit * base;
        base /= 16;

        if (lastDigit <= 9)
        {
            hex = hex + to_string(lastDigit);
        }
        else
        {
            char c = 'A' + lastDigit - 10;
            hex.push_back(c);
        }
    }

    cout << "\n\tDecimal: " << ans << endl
         << "\tHexadecimal: " << hex << endl;
}
