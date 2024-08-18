#include "common_util.h"
#include "message_logger.h"
#include<string.h>
#include <stdarg.h>

char testbuffer[10][1024] = {0};
int printcount = 0;

void print(const char *format, ...)
{
    static int count = 0;
    va_list args;
    va_start(args, format);
    vsprintf(testbuffer[count], format, args);
    va_end(args);
    printcount++;
    count++;
    if(count == 10)
    {
        count = 0;
    }
}
