#include "common_util.h"
#include "temperature_monitor.h"

BreachType inferBreach(double value, double lowerLimit, double upperLimit)
{
  return (value < lowerLimit) ? TOO_LOW :(value > upperLimit) ? TOO_HIGH : NORMAL;
}

BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC)
{
  int lowerLimit = 0;
  int upperLimit = 0;
  int lowerLimits[] = {0, 0, 0};
  int upperLimits[] = {35, 45, 40};

  lowerLimit = lowerLimits[coolingType];
  upperLimit = upperLimits[coolingType];

  return inferBreach(temperatureInC, lowerLimit, upperLimit);
}
