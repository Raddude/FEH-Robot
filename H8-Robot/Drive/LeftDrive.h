#ifndef LEFTDRIVE_H
#define LEFTDRIVE_H
#include "DriveBase.h"
#include "DriveConstants.h"


class LeftDrive : public DriveBase, public DriveConstants
{
public:
    LeftDrive();
    LeftDrive* getInstance();
    void driveLeftCorrected(int);
    int getLeftEncoderCount();
    double getLeftEncoderDistance();
    void resetLeftEncoder();
};

#endif // LEFTDRIVE_H
