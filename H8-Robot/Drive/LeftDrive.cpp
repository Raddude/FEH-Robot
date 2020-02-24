/*  LeftDrive.cpp
 *  Author: Jake Marchewitz
 *  Creation Date: 2/10/20
 *
 *  Purpose: This is a sub-class of DriveBase and contains any left-half specific methods.
 *
 *  Superclasses: DriveBase.cpp.
 *  Subclasses: MainDriveController.cpp.
 *  Used in: None.
 */

#include <FEHMotor.h>
#include <FEHIO.h>
#include "LeftDrive.h"
#include "DriveConstants.h"

using namespace std;

LeftDrive leftDrive;

DigitalEncoder leftEncoder(FEHIO::P0_1);

double leftErrorValues[100];







LeftDrive::LeftDrive()
{

}







/*  This is a wrapper for the left motor's drive function, meant primarily to control the direction of that motor.
 *
 *  int speed - A value in the range [-100, 100] that determines the motor's speed as a percentage of full power.
 */
void LeftDrive::driveLeftCorrected(int speed)
{
    driveLeftMotor(-speed);
}





/*  This is a wrapper for the left motor's PID function, it automagically fills in the left motor's constants and simplifies parameters
 *
 *  double setpoint - The target distance of the motor
 */
void LeftDrive::driveLeftPID(double setpoint)
{
    driveBase.driveMotorPID('L', setpoint, leftErrorValues, driveConstants.getKP('L'), driveConstants.getKI('L'), driveConstants.getKD('L'));

    driveBase.updatePreviousValues(setpoint - getLeftEncoderDistance(), leftErrorValues);
}

/*  This resets the leftErrorValues array
 */
void LeftDrive::resetLeftErrorValues()
{
    driveBase.resetPreviousValues(leftErrorValues);
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
    return leftEncoder.Counts()*getDistancePerTick();
}

/*  This method resets the tick count of the left encoder to 0.
 */
void LeftDrive::resetLeftEncoder()
{
    leftEncoder.ResetCounts();
}

