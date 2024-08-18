#ifndef COMMON_UTIL_H
#define COMMON_UTIL_H

#include <stdio.h>

typedef enum
{
  NORMAL,
  TOO_LOW,
  TOO_HIGH
} BreachType;

void sendToController(BreachType breachType);
void sendToEmail(BreachType breachType);

#endif
