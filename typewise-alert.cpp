#include "common_util.h"
#include "typewise-alert.h"
#include "message_logger.h"


void sendHighTempAlert(const char* recepient)
{
    print("To: %s\n", recepient);
    print("Hi, the temperature is too high\n");
}

void sendLowTempAlert(const char* recepient)
{
    print("To: %s\n", recepient);
    print("Hi, the temperature is too low\n");
}

void onNormalTemp(const char* recepient)
{
   return;
}

void sendToEmail(BreachType breachType)
{
  const char* recepient = "a.b@c.com";

  void (*messageType[])(const char* recepient) = {onNormalTemp,sendLowTempAlert,sendHighTempAlert};

  messageType[breachType](recepient);

}
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
