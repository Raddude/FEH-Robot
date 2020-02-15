#ifndef DRIVECONSTANTS_H
#define DRIVECONSTANTS_H


class DriveConstants
{
public:
    DriveConstants();
    static DriveConstants* getInstance();

    double getWheelDiameter();
    double getWheelSpan();
    double getTicksPerRotation();
    double getPI();
    double getDistancePerRotation();
    double getDistancePerTick();
    double getDistancePerFullTurn();
    double getTicksPerFullTurn();
    double getSleepAmount();

private:
    static DriveConstants *instance;
};

#endif // DRIVECONSTANTS_H
