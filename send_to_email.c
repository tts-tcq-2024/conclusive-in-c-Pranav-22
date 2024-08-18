#include "common_util.h"
#include "message_logger.h"
#include "send_to_email.h"

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
