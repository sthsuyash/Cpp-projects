#include <iostream>
#include <string>
using namespace std;

int countWords(string sentence)
{
    int i = 0, count = 0;
    while (sentence[i] != '\0')
    {
        if (sentence[i] == ' ')
        {
            count++;
        }
        i++;
    }
    return ++count;
}

int main()
{
    string sentence = "Hi my name is suyash! I live in kathmandu";
    cout << countWords(sentence) << endl;
    cout << sentence.length() << endl;
    return 0;
}
