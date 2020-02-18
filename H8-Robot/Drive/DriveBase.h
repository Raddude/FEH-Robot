#ifndef DRIVEBASE_H
#define DRIVEBASE_H

#include <FEHMotor.h>


class DriveBase
{
public:
    DriveBase();

    void driveLeftMotor(int);
    void driveRightMotor(int);

    void stopLeftMotor();
    void stopRightMotor();
};

extern DriveBase driveBase;

#endif // DRIVEBASE_H
