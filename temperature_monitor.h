#ifndef TEMPERATURE_MONITOR_H
#define TEMPERATURE_MONITOR_H

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

#endif
