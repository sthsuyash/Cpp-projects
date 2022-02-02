#include <bits/stdc++.h>
using namespace std;

int addBinary(int, int, int (*reverse)(int));
int reverse(int);

int main()
{
    int a, b;
    cout << "Enter two binary numbers: ";
    cin >> a >> b;
    cout << "The binary sum of " << a << " and " << b << " is: " << addBinary(a, b, &reverse);
    return 0;
}

int addBinary(int a, int b, int (*reverse)(int))
{
    int ans = 0;
    int prevCarry = 0;

    while (a > 0 && b > 0)
    {
        if (a % 2 == 0 && b % 2 == 0)
        {
            ans = ans * 10 + prevCarry;
            prevCarry = 0;
        }
        else if ((a % 2 == 0 && b % 2 == 1) || (a % 2 == 1 && b % 2 == 0))
        {
            if (prevCarry == 1)
            {
                ans = ans * 10 + 0;
                prevCarry = 1;
            }
            else
            {
                ans = ans * 10 + 1;
                prevCarry = 0;
            }
        }
        else
        {
            ans = ans * 10 + prevCarry;
            prevCarry = 1;
        }
        a /= 10;
        b /= 10;
    }

    while (a > 0)
    {
        if (prevCarry == 1)
        {
            if (a % 2 == 1)
            {
                ans = ans * 10 + 0;
                prevCarry = 1;
            }
            else
            {
                ans = ans * 10 + 1;
                prevCarry = 0;
            }
        }
        else
        {
            ans = ans * 10 + (a % 2);
        }
        a /= 10;
    }

    while (b > 0)
    {
        if (prevCarry == 1)
        {
            if (b % 2 == 1)
            {
                ans = ans * 10 + 0;
                prevCarry = 1;
            }
            else
            {
                ans = ans * 10 + 1;
                prevCarry = 0;
            }
        }
        else
        {
            ans = ans * 10 + (b % 2);
        }
        b /= 10;
    }

    if (prevCarry == 1)
    {
        ans = ans * 10 + 1;
    }

    ans = reverse(ans);
    return ans;
}

int reverse(int num)
{
    int ans = 0;
    while (num > 0)
    {
        int temp = num % 10;
        ans = ans * 10 + temp;
        num /= 10;
    }
    return ans;
}