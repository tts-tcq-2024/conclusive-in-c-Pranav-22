#include <gtest/gtest.h>
#include "common_util.h"
#include "temperature_monitor.h"
#include "typewise-alert.h"
extern char testbuffer[10][1024];
extern int printcount;

TEST(TypeWiseAlertTestSuite,InfersBreachAccordingToLimits) {
    BatteryCharacter batteryChar;
    batteryChar.coolingType = HI_ACTIVE_COOLING;
    double temperatureInC = 50.0;
    checkAndAlert(TO_CONTROLLER, batteryChar, temperatureInC);
    EXPECT_STREQ("feed : 2",testbuffer[0]);
}


TEST(TypeWiseAlertTestSuite,EmailInfersBreachAccordingToLimits) {
    BatteryCharacter batteryChar;
    batteryChar.coolingType = HI_ACTIVE_COOLING;
    double temperatureInC = 50.0;
    checkAndAlert(TO_EMAIL, batteryChar, temperatureInC);
    EXPECT_STREQ("Hi, the temperature is too high",testbuffer[1]);
}

TEST(TypeWiseAlertTestSuite,PassivecoolInfersBreachToLimits) {
    BatteryCharacter batteryChar;
    batteryChar.coolingType = PASSIVE_COOLING;
    double temperatureInC = 45.0;
    checkAndAlert(TO_CONTROLLER, batteryChar, temperatureInC);
    EXPECT_STREQ("feed : 2",testbuffer[0]);
}


TEST(TypeWiseAlertTestSuite,PasivecoolEmailInfersBreachToLimits) {
    BatteryCharacter batteryChar;
    batteryChar.coolingType = PASSIVE_COOLING;
    double temperatureInC = 45.0;
    checkAndAlert(TO_EMAIL, batteryChar, temperatureInC);
    EXPECT_STREQ("Hi, the temperature is too high",testbuffer[1]);
}

TEST(TypeWiseAlertTestSuite,ActivecoolInfersBreachToLimits) {
    BatteryCharacter batteryChar;
    batteryChar.coolingType = HI_ACTIVE_COOLING;
    double temperatureInC = -5.0;
    checkAndAlert(TO_CONTROLLER, batteryChar, temperatureInC);
    EXPECT_STREQ("feed : 1",testbuffer[0]);
}


TEST(TypeWiseAlertTestSuite,ActivecoolEmailInfersBreachToLimits) {
    BatteryCharacter batteryChar;
    batteryChar.coolingType = HI_ACTIVE_COOLING;
    double temperatureInC = -5.0;
    checkAndAlert(TO_EMAIL, batteryChar, temperatureInC);
    EXPECT_STREQ("Hi, the temperature is too low",testbuffer[1]);
}

TEST(TypeWiseAlertTestSuite,PassivecoolEmailInfersBreachToLimits) {
    BatteryCharacter batteryChar;
    batteryChar.coolingType = PASSIVE_COOLING;
    double temperatureInC = -10;
    checkAndAlert(TO_EMAIL, batteryChar, temperatureInC);
    EXPECT_STREQ("Hi, the temperature is too low",testbuffer[1]);
}

TEST(TypeWiseAlertTestSuite,MedActivecoolInfersBreachToLimits) {
    BatteryCharacter batteryChar;
    batteryChar.coolingType = MED_ACTIVE_COOLING;
    double temperatureInC = 30;
    checkAndAlert(TO_CONTROLLER, batteryChar, temperatureInC);
    EXPECT_STREQ("feed : 0",testbuffer[0]);
}


TEST(TypeWiseAlertTestSuite,MedActivecoolEmailInfersBreachToLimits) {
    BatteryCharacter batteryChar;
    batteryChar.coolingType = MED_ACTIVE_COOLING;
    double temperatureInC = 30;
    checkAndAlert(TO_EMAIL, batteryChar, temperatureInC);
    EXPECT_STREQ("",testbuffer[0]);
}

TEST(TypeWiseAlertTestSuite,MedActivecoolEmailInfersBreachToLimitsRecepientcheck) {
    BatteryCharacter batteryChar;
    batteryChar.coolingType = MED_ACTIVE_COOLING;
    double temperatureInC = 50;
    checkAndAlert(TO_EMAIL, batteryChar, temperatureInC);
    EXPECT_STREQ("To: a.b@c.com",testbuffer[0]);
    EXPECT_STREQ("Hi, the temperature is too high",testbuffer[1]);
    EXPECT_EQ(2,printcount);
}

TEST(TypeWiseAlertTestSuite,PassivecoolInfersBreachToLimitscontroller) {
    BatteryCharacter batteryChar;
    batteryChar.coolingType = PASSIVE_COOLING;
    double temperatureInC = 0;
    checkAndAlert(TO_CONTROLLER, batteryChar, temperatureInC);
    EXPECT_STREQ("feed : 0",testbuffer[0]);
    EXPECT_EQ(1,printcount);
}
