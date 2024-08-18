#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include "message_logger.h"

char testbuffer[10][1024];
int printcount;

void print(const char *format, ...)
{
    static int count = 0;
    va_list args;
    va_start(args, format);
    vsprintf(testbuffer[count], format, args);
    va_end(args);
    printcount++;
    count++;
}
