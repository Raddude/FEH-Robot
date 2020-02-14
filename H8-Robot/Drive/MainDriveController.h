#ifndef MAINDRIVECONTROLLER_H
#define MAINDRIVECONTROLLER_H
#include "LeftDrive.h"
#include "RightDrive.h"
#include "DriveConstants.h"


class MainDriveController : public LeftDrive, public RightDrive
{
public:
    MainDriveController();
    MainDriveController* getInstance();
    void driveByPower(int, int);
    bool driveByEncoders(double, int);
    bool driveByEncoders(double, int, double, int);
    bool driveByEncoders(int, int, int, int);
    bool turnLeft(double, int);
    bool turnRight(double, int);
    void stopMotors();
    void resetEncoders();
    double getTickCountFromDistance(double);
    double getDistanceFromAngle(double);

};

#endif // MAINDRIVECONTROLLER_H
