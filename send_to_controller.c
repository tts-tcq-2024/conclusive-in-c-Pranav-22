#include "common_util.h"
#include "message_logger.h"

void sendToController(BreachType breachType)
{
  const unsigned short header = 0xfeed;
  print("%x : %x\n", header, breachType);
}
