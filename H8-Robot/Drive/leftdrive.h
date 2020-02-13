#ifndef LEFTDRIVE_H
#define LEFTDRIVE_H
#include "drivebase.h"
#include "driveconstants.h"


class LeftDrive : public DriveBase, public DriveConstants
{
public:
    LeftDrive();
    void driveLeftCorrected(int);
    int getLeftEncoderCount();
    double getLeftEncoderDistance();
    void resetLeftEncoder();
};

#endif // LEFTDRIVE_H
