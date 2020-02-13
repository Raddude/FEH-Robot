#ifndef DRIVECONSTANTS_H
#define DRIVECONSTANTS_H


class DriveConstants
{
public:
    DriveConstants();
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
