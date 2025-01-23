#include "main.h"

void clearBuffer()
{
    cin.clear();                    // clear error flags
    cin.ignore(maxstream, newline); // clears the buffer for maxstream (refer to macros.h)
}
