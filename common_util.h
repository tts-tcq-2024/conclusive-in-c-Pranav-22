#ifndef COMMON_UTIL_H
#define COMMON_UTIL_H

#include <stdio.h>

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

typedef enum
{
  NORMAL,
  TOO_LOW,
  TOO_HIGH
} BreachType;


void sendToController(BreachType breachType);
void sendToEmail(BreachType breachType);
BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC)

#endif
