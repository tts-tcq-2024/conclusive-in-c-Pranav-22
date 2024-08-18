#ifndef TYPEWISE_ALERT_H
#define TYPEWISE_ALERT_H

#include "temperature_monitor.h"

typedef enum {
  TO_CONTROLLER,
  TO_EMAIL
} AlertTarget;

typedef struct {
  CoolingType coolingType;
  char brand[48];
} BatteryCharacter;

void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC);
#endif
