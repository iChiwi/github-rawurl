#include "main.h"

int main()
{
    // Get the initial URL and convert it to a raw GitHub URL
    string newURL = updateURL(getURL());
    cout << "The raw GitHub URL was copied to your clipboard." << endl;
    copyToClipboard(newURL);

    bool repeatFunc = 1; // Flag to control the loop
    char repeatChar;     // Variable to store user input

    while (repeatFunc)
    {
        // Prompt the user to generate another raw URL or exit
        cout << "Do you want to generate another raw URL? Enter Y for yes and N for no: ";
        cin >> repeatChar;

        clearBuffer(); // Clear the input buffer

        switch (repeatChar)
        {
        case 'Y':
        case 'y':
            // Generate a new raw URL
            newURL = updateURL(getURL());
            break;
        case 'N':
        case 'n':
            // Exit the loop
            repeatFunc = 0;
            cout << "Thank you for using this tool. Press ENTER to exit.\n";
            cin.get();
            continue;
        default:
            // Handle invalid input
            cout << "You entered an invalid character, use Y or N: ";
            break;
        }
        // Copy the new raw URL to the clipboard
        copyToClipboard(newURL);
        cout << "The raw GitHub URL was copied to your clipboard." << endl;
    }
    return 0;
}
