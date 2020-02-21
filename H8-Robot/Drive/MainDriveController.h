#ifndef MAINDRIVECONTROLLER_H
#define MAINDRIVECONTROLLER_H
#include "LeftDrive.h"
#include "RightDrive.h"
#include "DriveConstants.h"


class MainDriveController : public LeftDrive, public RightDrive
{
public:
    MainDriveController();

    void driveByPower(int, int);

    bool driveByEncoders(double, int);
    bool driveByEncoders(double, int, double, int);
    bool driveByEncoders(int, int, int, int);

    bool driveByPID(double, int);
    bool driveByPID(double, int, double, int);
    bool driveByPID(int, int, int, int);

    bool turnLeft(double, int);
    bool turnRight(double, int);

    bool turnLeftPID(double, int);
    bool turnRightPID(double, int);

    void stopMotors();
    void resetEncoders();

    double getTickCountFromDistance(double);
    double getDistanceFromAngle(double);
};

extern MainDriveController drive;

#endif // MAINDRIVECONTROLLER_H
