#ifndef RIGHTDRIVE_H
#define RIGHTDRIVE_H
#include "drivebase.h"


class RightDrive : public DriveBase
{
public:
    RightDrive();
    void driveRightCorrected(int);
};

#endif // RIGHTDRIVE_H
