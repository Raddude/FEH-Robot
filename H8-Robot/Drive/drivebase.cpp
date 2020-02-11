/*  DriveBase.cpp
 *  Author: Jake Marchewitz
 *  Creation Date: 2/10/20
 *
 *  Purpose: This file acts as a template for each half of the robot's drive control. The purpose of this structure is to account for the fact that the motors are mounted in opposite directions. The "drive forward 10 units" method for both sides will make the robot move forward 10 units, but the directions the motors will be turning are opposite.
 *
 *  Superclasses: None.
 *  Subclasses: LeftDrive.cpp, RightDrive.cpp.
 *  Used in: None.
 *  Uses: None.
 */

#include <FEHMotor.h>
#include "drivebase.h"



FEHMotor leftMotor(FEHMotor::Motor0, 9.0);
FEHMotor rightMotor(FEHMotor::Motor1, 9.0);







DriveBase::DriveBase()
{

}







//Drive motors at the exact percent listed, without correcting for the mounting direction
void DriveBase::driveLeftMotor(int speed)
{
    leftMotor.SetPercent(speed);
}

void DriveBase::driveRightMotor(int speed)
{
    rightMotor.SetPercent(speed);
}



//Stop motors
void DriveBase::stopLeftMotor()
{
    leftMotor.Stop();
}

void DriveBase::stopRightMotor()
{
    rightMotor.Stop();
}
