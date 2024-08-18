#ifndef TYPEWISE_ALERT_H
#define TYPEWISE_ALERT_H
#include <stdio.h>
#include<string.h>
#include <stdarg.h>
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


typedef enum {
  TO_CONTROLLER,
  TO_EMAIL
} AlertTarget;


void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC);
BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC);
void sendToController(BreachType breachType);
void sendToEmail(BreachType breachType);

#endif
