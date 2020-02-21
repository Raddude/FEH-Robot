#ifndef COMMANDS_H
#define COMMANDS_H

#include "General/Optosensors.h"


class Commands
{
public:
    Commands();

    void preMatchReset();
    bool configureOptosensors();
    bool configureCdSCell();
    bool configureLimitSwitches();
    bool showBatteryVoltage();

    bool followLineForDistance(double, int);
    bool driveUntilLimitSwitch(char, int);
};

extern Commands commands;

#endif // COMMANDS_H
