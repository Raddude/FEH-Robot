/*  LeftDrive.cpp
 *  Author: Jake Marchewitz
 *  Creation Date: 2/10/20
 *
 *  Purpose: This is a sub-class of DriveBase and contains any left-half specific methods.
 *
 *  Superclasses: DriveBase.cpp.
 *  Subclasses: None.
 *  Used in: MainDriveController.cpp.
 *  Uses: None.
 */

#include <FEHMotor.h>
#include <FEHIO.h>
#include "leftdrive.h"

#define WHEEL_DIAMETER 2.5
#define TICKS_PER_ROTATION 318
#define PI 3.141592653589793238463
#define DISTANCE_PER_ROTATION (PI*WHEEL_DIAMETER)
#define DISTANCE_PER_TICK (DISTANCE_PER_ROTATION/TICKS_PER_ROTATION)

DigitalEncoder leftEncoder(FEHIO::P0_1);








LeftDrive::LeftDrive()
{

}







//Corrected left half drive function
void LeftDrive::driveLeftCorrected(int speed)
{
    driveLeftMotor(speed);
}



//Encoder methods
int LeftDrive::getLeftEncoderCount()
{
    return leftEncoder.Counts();
}

double LeftDrive::getLeftEncoderDistance()
{
    return leftEncoder.Counts()*DISTANCE_PER_TICK;
}

void LeftDrive::resetLeftEncoder()
{
    leftEncoder.ResetCounts();
}

