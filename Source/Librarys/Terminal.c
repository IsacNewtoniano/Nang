#include "../Handlers/Types.h"


#include <windows.h>

i32 terminal_width(void)
{
    CONSOLE_SCREEN_BUFFER_INFO info;

    if (!GetConsoleScreenBufferInfo(
            GetStdHandle(STD_OUTPUT_HANDLE),
            &info))
        return 0; // fallback

    return info.srWindow.Right - info.srWindow.Left + 1;
}

void progress(i32 percent, i32 reserve_space)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO info;
    i32 width;

    if (!GetConsoleScreenBufferInfo(out, &info)){
      width = 13;
    }
    else {
      width = info.srWindow.Right - info.srWindow.Left + 1;
    }

    char buffer[512];

    i32 bar_width = width - 8 - reserve_space; // "[... ] 100%"
    if (bar_width < 1)
        bar_width = 5;

    i32 filled = (bar_width * percent) / 100;

    i32 pos = 0;

    buffer[pos++] = '\r';
    buffer[pos++] = '[';

    for (i32 i = 0; i < bar_width; i++)
        buffer[pos++] = i < filled ? '#' : '-';

    buffer[pos++] = ']';
    buffer[pos++] = ' ';

    buffer[pos++] = (percent / 100) ? ('0' + (percent / 100)) : ' ';
    buffer[pos++] = '0' + ((percent / 10) % 10);
    buffer[pos++] = '0' + (percent % 10);
    buffer[pos++] = '%';

    DWORD written;
    WriteFile(out, buffer, pos, &written, NULL);
}