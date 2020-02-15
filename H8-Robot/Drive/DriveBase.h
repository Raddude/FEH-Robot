#ifndef DRIVEBASE_H
#define DRIVEBASE_H

#include <FEHMotor.h>


class DriveBase
{
public:
    DriveBase();
    static DriveBase* getInstance();

    void driveLeftMotor(int);
    void driveRightMotor(int);

    void stopLeftMotor();
    void stopRightMotor();

private:
    static DriveBase *instance;
};

#endif // DRIVEBASE_H
