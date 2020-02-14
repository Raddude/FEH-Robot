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

private:

};

#endif // DRIVEBASE_H
