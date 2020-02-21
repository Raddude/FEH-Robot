#ifndef DRIVEBASE_H
#define DRIVEBASE_H

#include <FEHMotor.h>


class DriveBase
{
public:
    DriveBase();

    void driveLeftMotor(int);
    void driveRightMotor(int);

    void driveMotorPID(char, int, double*, double, double, double);
    void driveMotorPID(char, double, double*, double, double, double);

    double getAreaOfValues(double*);
    double getSlopeOfValues(double*);

    void stopLeftMotor();
    void stopRightMotor();
};

extern DriveBase driveBase;

#endif // DRIVEBASE_H
