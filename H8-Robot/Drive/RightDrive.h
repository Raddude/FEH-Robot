#ifndef RIGHTDRIVE_H
#define RIGHTDRIVE_H
#include "DriveBase.h"
#include "DriveConstants.h"


class RightDrive : public DriveBase, public DriveConstants
{
public:
    RightDrive();

    void driveRightCorrected(int);
    void driveRightPID(double);
    void resetRightErrorValues();

    int getRightEncoderCount();
    double getRightEncoderDistance();
    void resetRightEncoder();
};

extern RightDrive rightDrive;

#endif // RIGHTDRIVE_H
