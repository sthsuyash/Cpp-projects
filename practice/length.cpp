#include <iostream>
#include <string>
using namespace std;

int count(string word)
{
    int i = 0, count = 0;
    while (word[i] != '\0')
    {
        count++;
        i++;
    }
    return count;
}

int main()
{
    string name = "Suyash";
    cout << count(name) << endl;
    cout << name.length();
    return 0;
}