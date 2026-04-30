#ifdef _WIN32

#include <windows.h>

#endif

void enableVirtualTerminal()
{
#ifdef _WIN32

    HANDLE hOut =
        GetStdHandle(STD_OUTPUT_HANDLE);

    if (hOut == INVALID_HANDLE_VALUE)
    {
        return;
    }

    DWORD mode = 0;

    if (!GetConsoleMode(hOut, &mode))
    {
        return;
    }

    mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;

    SetConsoleMode(hOut, mode);

#endif
}