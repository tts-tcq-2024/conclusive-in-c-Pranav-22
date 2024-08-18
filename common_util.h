#ifndef COMMON_UTIL_H
#define COMMON_UTIL_H

#include <stdio.h>
#include<string.h>
#include <stdarg.h>
#include <assert.h>

typedef enum
{
  NORMAL,
  TOO_LOW,
  TOO_HIGH
} BreachType;

void sendToController(BreachType breachType);
void sendToEmail(BreachType breachType);

#endif
