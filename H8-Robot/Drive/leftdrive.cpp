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







/*  This is a wrapper for the left motor's drive function, meant primarily to control the direction of that motor.
 *
 *  int speed - A value in the range [-100, 100] that determines the motor's speed as a percentage of full power.
 */
void LeftDrive::driveLeftCorrected(int speed)
{
    driveLeftMotor(speed);
}





/*  This method returns the output of the left encoder in terms of raw encoder ticks.
 */
int LeftDrive::getLeftEncoderCount()
{
    return leftEncoder.Counts();
}

/*  This method returns the output of the left encoder in terms of inches.
 */
double LeftDrive::getLeftEncoderDistance()
{
    return leftEncoder.Counts()*DISTANCE_PER_TICK;
}

/*  This method resets the tick count of the left encoder to 0.
 */
void LeftDrive::resetLeftEncoder()
{
    leftEncoder.ResetCounts();
}

