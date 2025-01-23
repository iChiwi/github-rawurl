#include "main.h"

string updateURL(string link) // Function receives link as a parameter
{
    // Looks for github.com and replaces it
    size_t pos = link.find("github.com");
    if (pos != string::npos)
    {
        link.replace(pos, 10, "raw.githubusercontent.com");
    }

    // Looks for blob and replaces it
    pos = link.find("blob/");
    if (pos != string::npos)
    {
        link.replace(pos, 5, "refs/heads/");
    }

    // Looks for ?raw=true and omits it
    pos = link.find("?raw=true");
    if (pos != string::npos)
    {
        link.erase(pos, 9);
    }
    return link;
}
