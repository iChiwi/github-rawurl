#include "main.h"

void copyToClipboard(const string text)
{
    if (OpenClipboard(nullptr))
    {
        EmptyClipboard();

        HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE, (text.size() + 1) * sizeof(char));
        if (hGlobal)
        {
            char *pClipboardData = static_cast<char *>(GlobalLock(hGlobal));
            if (pClipboardData)
            {
                memcpy(pClipboardData, text.c_str(), (text.size() + 1) * sizeof(char));
                GlobalUnlock(hGlobal);

                if (!SetClipboardData(CF_TEXT, hGlobal))
                {
                    GlobalFree(hGlobal);
                }
            }
            else
            {
                GlobalFree(hGlobal);
            }
        }
        CloseClipboard();
    }
}
