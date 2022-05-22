// decryption function
#include <iostream>
#include <string>

void decrypt()
{
    std::string text;
    char temp;
    int key;

    system("cls");
    std::cout << "\nEnter text to be decrypted: ";
    std::cin >> text;
    std::cout << "Enter key: ";
    std::cin >> key;

    for (int i = 0; i < text.length(); i++)
    {
        temp = text[i];
        if (temp >= 'a' && temp <= 'z')
        {
            temp -= key;
            if (temp < 'a')
            {
                temp += 'z' - 'a' + 1;
            }
            text[i] = temp;
        }
        else if (temp >= 'A' && temp <= 'Z')
        {
            temp -= key;
            if (temp < 'A')
            {
                temp += 'Z' - 'A' + 1;
            }
            text[i] = temp;
        }
    }
    std::cout << "\nDecrypted Message: " << text << std::endl;
}
