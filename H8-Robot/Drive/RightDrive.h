#ifndef RIGHTDRIVE_H
#define RIGHTDRIVE_H
#include "DriveBase.h"
#include "DriveConstants.h"


class RightDrive : public DriveBase, public DriveConstants
{
public:
    RightDrive();
    RightDrive* getInstance();
    void driveRightCorrected(int);
    int getRightEncoderCount();
    double getRightEncoderDistance();
    void resetRightEncoder();
};

#endif // RIGHTDRIVE_H
