#include "typewise-alert.h"
#include "common_util.h"
void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC)
{
  BreachType breachType = classifyTemperatureBreach(batteryChar.coolingType, temperatureInC);

  /*Switch case is reduced by replacing with function pointers*/
  void (*sendToTarget[])(BreachType breachType) = {sendToController,sendToEmail};

  sendToTarget[alertTarget](breachType);
}
