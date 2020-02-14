#ifndef DRIVECONSTANTS_H
#define DRIVECONSTANTS_H


class DriveConstants
{
public:
    DriveConstants();
    DriveConstants* getInstance();
    double getWheelDiameter();
    double getWheelSpan();
    double getTicksPerRotation();
    double getPI();
    double getDistancePerRotation();
    double getDistancePerTick();
    double getDistancePerFullTurn();
    double getTicksPerFullTurn();
    double getSleepAmount();

};

#endif // DRIVECONSTANTS_H
