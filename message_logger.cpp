#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include "message_logger.h"

char testbuffer[10][1024];
int printcount;

void print(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    vsprintf(testbuffer[printcount], format, args);
    va_end(args);
    printcount++;
}
