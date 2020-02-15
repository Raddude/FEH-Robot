#ifndef LEFTDRIVE_H
#define LEFTDRIVE_H
#include "DriveBase.h"
#include "DriveConstants.h"


class LeftDrive : public DriveBase, public DriveConstants
{
public:
    LeftDrive();
    static LeftDrive* getInstance();
    void driveLeftCorrected(int);
    int getLeftEncoderCount();
    double getLeftEncoderDistance();
    void resetLeftEncoder();

private:
    static LeftDrive *instance;
};

#endif // LEFTDRIVE_H
