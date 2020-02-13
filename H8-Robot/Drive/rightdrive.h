#ifndef RIGHTDRIVE_H
#define RIGHTDRIVE_H
#include "drivebase.h"
#include "driveconstants.h"


class RightDrive : public DriveBase, public DriveConstants
{
public:
    RightDrive();
    void driveRightCorrected(int);
    int getRightEncoderCount();
    double getRightEncoderDistance();
    void resetRightEncoder();
};

#endif // RIGHTDRIVE_H
