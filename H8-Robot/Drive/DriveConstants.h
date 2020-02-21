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

    double getKP(char);
    double getKI(char);
    double getKD(char);
    int getBufferSize();
    int getSlopeDomain();
};

extern DriveConstants driveConstants;

#endif // DRIVECONSTANTS_H
