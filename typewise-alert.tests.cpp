#include <gtest/gtest.h>
#include "common_util.h"
#include "temperature_monitor.h"
#include "typewise-alert.h"
extern char testbuffer[10][1024];

TEST(TypeWiseAlertTestSuite,InfersBreachAccordingToLimits) {
    BatteryCharacter batteryChar;
    batteryChar.coolingType = HI_ACTIVE_COOLING;
    double temperatureInC = 50.0;
    checkAndAlert(TO_CONTROLLER, batteryChar, temperatureInC);
    printf("%s",testbuffer[0]);
    //ASSERT_EQ("feed : 2",testbuffer[0]);
}
