#include "message_logger.h"
#include "send_to_controller.h"

void sendToController(BreachType breachType)
{
  const unsigned short header = 0xfeed;
  print("%x : %x\n", header, breachType);
}
