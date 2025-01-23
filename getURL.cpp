#include "main.h"

string getURL()
{
    string link;
    cout << "Enter the link of the file to generate raw URL: ";
    getline(cin, link); // Gets complete line from user as input and stores it under variable link
    return link;        // Returns link's value
}
