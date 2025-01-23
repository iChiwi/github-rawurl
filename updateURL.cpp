#include "main.h"

string updateURL(string link)
{
    size_t pos = link.find("github.com");
    if (pos != string::npos)
    {
        link.replace(pos, 10, "raw.githubusercontent.com");
    }

    pos = link.find("blob/");
    if (pos != string::npos)
    {
        link.replace(pos, 5, "refs/heads/");
    }

    pos = link.find("?raw=true");
    if (pos != string::npos)
    {
        link.erase(pos, 9);
    }
    return link;
}
