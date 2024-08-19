#include "common_util.h"
#include "message_logger.h"

void sendHighTempAlert(const char* recepient)
{
    print("To: %s", recepient);
    print("Hi, the temperature is too high");
}

void sendLowTempAlert(const char* recepient)
{
    print("To: %s", recepient);
    print("Hi, the temperature is too low");
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
