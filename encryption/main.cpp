#include <iostream>
#include <string>
#include <windows.h>
#include "encrypt.h"
#include "decrypt.h"

// function declaration //// definition at end //
void dots(int);

// driver function
int main()
{
    // variable to store the condition of program to re-run
    bool repeat = true;
    // repeat until the user doesn't quit
    do
    {
        int choice, main_choice;
        system("cls");
        std::cout << "\nEncryption and Decryption using C++\n"
                  << std::endl;
        // pause for 1 second before displaying options
        Sleep(1000);
        std::cout << "What operation do you want to perform?\n";
        std::cout << "Press\t'0' to exit\n\t'1' for encryption\n\t'2' for Decryption\n>> ";
        std::cin >> choice;

        switch (choice)
        {
        case 0:
            repeat = false;
            goto end;
            break;

        case 1:
            encrypt();
            std::cout << std::endl;
            break;

        case 2:
            decrypt();
            std::cout << std::endl;
            break;

        default:
            std::cout << "\aEnter a valid operation.\n"
                      << std::endl;
            main();
            break;
        }

    // loop through the process until user exits
    re:
        std::cout << "Press: \t'0' to exit\n\t'1' to goto main menu.\n>> ";
        std::cin >> main_choice;

        switch (main_choice)
        {
        case 0:
            repeat = false;
            goto end;
            break;

        case 1:
            std::cout << "Returning to main menu. ";
            dots(6);
            main();
            break;

        default:
            system("cls");
            std::cout << "\aEnter valid option.\n";
            goto re;
            break;
        }
    } while (repeat);
// program ending text
end:
    std::cout << "End of program.\n";
    return 0;
}

// function to simulate loading experience
void dots(int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << ". ";
        Sleep(200);
    }
}
