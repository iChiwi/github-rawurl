#include "main.h"

int main()
{
    string newURL = updateURL(getURL());
    cout << "Your raw GitHub URL was copied to clipboard." << endl;
    copyToClipboard(newURL);
    bool repeatFunc = 1;
    char repeatChar;
    while (repeatFunc)
    {
        cout << "Do you want to generate another raw URL? Enter Y for yes and N for no: ";
        cin >> repeatChar;

        clearBuffer();

        switch (repeatChar)
        {
        case 'Y':
        case 'y':
            newURL = updateURL(getURL());
            break;
        case 'N':
        case 'n':
            repeatFunc = 0;
            cout << "Thank you for using this tool. Press ENTER to exit.\n";
            cin.get();
            continue;
        default:
            cout << "You entered an invalid character, use Y or N: ";
            break;
        }
        copyToClipboard(newURL);
        cout << "Your raw GitHub URL was copied to clipboard." << endl;
    }
    return 0;
}
