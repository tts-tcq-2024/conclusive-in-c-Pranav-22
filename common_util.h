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

typedef enum
{
  PASSIVE_COOLING,
  HI_ACTIVE_COOLING,
  MED_ACTIVE_COOLING
} CoolingType;

typedef struct {
  CoolingType coolingType;
  char brand[48];
} BatteryCharacter;

BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC);
void sendToController(BreachType breachType);
void sendToEmail(BreachType breachType);

#endif
