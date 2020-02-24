#ifndef LEFTDRIVE_H
#define LEFTDRIVE_H
#include "DriveBase.h"
#include "DriveConstants.h"


class LeftDrive : public DriveBase, public DriveConstants
{
public:
    LeftDrive();

    void driveLeftCorrected(int);
    void driveLeftPID(double);
    void resetLeftErrorValues();

    int getLeftEncoderCount();
    double getLeftEncoderDistance();
    void resetLeftEncoder();
};

extern LeftDrive leftDrive;

#endif // LEFTDRIVE_H
