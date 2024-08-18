#include "common_util.h"
#include "temperature_monitor.h"
#include "typewise-alert.h"
#include "send_to_controller.h"
#include "send_to_email.h"


void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC)
{
  BreachType breachType = classifyTemperatureBreach(batteryChar.coolingType, temperatureInC);

  /*Switch case is reduced by replacing with function pointers*/
  void (*sendToTarget[])(BreachType breachType) = {sendToController,sendToEmail};

  sendToTarget[alertTarget](breachType);
}
