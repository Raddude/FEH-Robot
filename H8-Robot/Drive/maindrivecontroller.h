#ifndef MAINDRIVECONTROLLER_H
#define MAINDRIVECONTROLLER_H
#include "leftdrive.h"
#include "rightdrive.h"


class MainDriveController : public LeftDrive, public RightDrive
{
public:
    MainDriveController();
    void driveByPower(int, int);
    void driveByEncoders(double, int);
    void driveByEncoders(double, int, double, int);
    void turnLeft(int);
    void turnRight(int);
    void stopMotors();
};

#endif // MAINDRIVECONTROLLER_H
