#ifndef TYPEWISE_ALERT_H
#define TYPEWISE_ALERT_H

typedef enum {
  TO_CONTROLLER,
  TO_EMAIL
} AlertTarget;


void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC);

#endif
