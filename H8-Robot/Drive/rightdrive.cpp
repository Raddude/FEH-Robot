/*  RightDrive.cpp
 *  Author: Jake Marchewitz
 *  Creation Date: 2/10/20
 *
 *  Purpose: This is a sub-class of DriveBase and contains any right-half specific methods.
 *
 *  Superclasses: DriveBase.cpp.
 *  Subclasses: None.
 *  Used in: MainDriveController.cpp.
 *  Uses: None.
 */

#include <FEHMotor.h>
#include <FEHIO.h>
#include "rightdrive.h"

#define WHEEL_DIAMETER 2.5
#define TICKS_PER_ROTATION 318
#define PI 3.141592653589793238463
#define DISTANCE_PER_ROTATION (PI*WHEEL_DIAMETER)
#define DISTANCE_PER_TICK (DISTANCE_PER_ROTATION/TICKS_PER_ROTATION)

DigitalEncoder rightEncoder(FEHIO::P0_0);







RightDrive::RightDrive()
{

}







//Corrected right half drive
void RightDrive::driveRightCorrected(int speed)
{
    driveRightMotor(speed);
}



//Encoder methods
int RightDrive::getRightEncoderCount()
{
    return rightEncoder.Counts();
}

double RightDrive::getRightEncoderDistance()
{
    return rightEncoder.Counts()*DISTANCE_PER_TICK;
}

void RightDrive::resetRightEncoder()
{
    rightEncoder.ResetCounts();
}
