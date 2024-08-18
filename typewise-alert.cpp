#include "common_util.h"
#include "typewise-alert.h"
#include "message_logger.h"

void sendToController(BreachType breachType)
{
  const unsigned short header = 0xfeed;
  print("%x : %x\n", header, breachType);
}


void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC)
{
  BreachType breachType = classifyTemperatureBreach(batteryChar.coolingType, temperatureInC);

  /*Switch case is reduced by replacing with function pointers*/
  void (*sendToTarget[])(BreachType breachType) = {sendToController,sendToEmail};

  sendToTarget[alertTarget](breachType);
}
