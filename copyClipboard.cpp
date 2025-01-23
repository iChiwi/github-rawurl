// I did not create this function, I have used one that was readily available.

#include "main.h"

void copyToClipboard(const string text)
{
    if (OpenClipboard(nullptr)) // Opens the clipboard for modifying
    {
        EmptyClipboard(); // Empties the clipboard before modifying

        HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE, (text.size() + 1) * sizeof(char)); // Allocates a movable global memory object for the text
        if (hGlobal)
        {
            char *pClipboardData = static_cast<char *>(GlobalLock(hGlobal)); // Locks the global memory object and returns a pointer to the first byte of the memory block
            if (pClipboardData)
            {
                memcpy(pClipboardData, text.c_str(), (text.size() + 1) * sizeof(char)); // Copies the text to the allocated memory
                GlobalUnlock(hGlobal);                                                  // Unlocks the global memory object

                if (!SetClipboardData(CF_TEXT, hGlobal)) // Places the data on the clipboard in CF_TEXT format
                {
                    GlobalFree(hGlobal); // Frees the global memory object if setting clipboard data fails
                }
            }
            else
            {
                GlobalFree(hGlobal); // Frees the global memory object if locking the memory fails
            }
            CloseClipboard(); // Closes the clipboard after modifying
        }
    }
