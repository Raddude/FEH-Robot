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
#include "RightDrive.h"
#include "DriveConstants.h"

using namespace std;

DigitalEncoder rightEncoder(FEHIO::P0_0);







RightDrive::RightDrive()
{

}







/*  This is a wrapper for the right motor's drive function, meant primarily to control the direction of that motor.
 *
 *  int speed - A value in the range [-100, 100] that determines the motor's speed as a percentage of full power.
 */
void RightDrive::driveRightCorrected(int speed)
{
    driveRightMotor(speed);
}





/*  This method returns the output of the right encoder in terms of raw encoder ticks.
 */
int RightDrive::getRightEncoderCount()
{
    return rightEncoder.Counts();
}

/*  This method returns the output of the right encoder in terms of inches.
 */
double RightDrive::getRightEncoderDistance()
{
    return rightEncoder.Counts()*getDistancePerTick();
}

/*  This method resets the tick count of the right encoder to 0.
 */
void RightDrive::resetRightEncoder()
{
    rightEncoder.ResetCounts();
}
