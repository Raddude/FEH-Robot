#ifndef COMMANDS_H
#define COMMANDS_H


class Commands
{
public:
    Commands();

    void preMatchReset();
    void postMoveReset();
    void postMatchActions();

    bool configureOptosensors();
    bool configureCdSCell();
    bool configureLimitSwitches();
    bool showBatteryVoltage();

    bool followLineForDistance(double, int);
    bool driveUntilLightDetected(double, int);
    bool driveUntilLimitSwitch(char, int);
    bool pivotUntilBackLimitSwitch(char, int);
};

extern Commands commands;

#endif // COMMANDS_H
