#ifndef DRIVECONSTANTS_H
#define DRIVECONSTANTS_H


class DriveConstants
{
public:
    DriveConstants();

    int straightSpeed();
    int turnSpeed();

    double getWheelDiameter();
    double getWheelSpan();
    double getTicksPerRotation();
    double getPI();
    double getDistancePerRotation();
    double getDistancePerTick();
    double getDistancePerFullTurn();
    double getTicksPerFullTurn();
    int getOvershootTicks(char, int);

    double getKP(char);
    double getKI(char);
    double getKD(char);
    int getBufferSize();
    int getSlopeDomain();
    double getPIDErrorMargin();
};

extern DriveConstants driveConstants;

#endif // DRIVECONSTANTS_H
