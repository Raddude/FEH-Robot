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
#include <FEHIO.h>
#include <math.h>
#include "DriveBase.h"

using namespace std;

DriveBase* DriveBase::instance = 0;

FEHMotor leftMotor(FEHMotor::Motor0, 9.0);
FEHMotor rightMotor(FEHMotor::Motor1, 9.0);







DriveBase::DriveBase()
{

}

/*  This returns the singleton instance of DriveBase.cpp
 */
DriveBase* DriveBase::getInstance()
{
    if (instance == 0)
    {
        instance = new DriveBase();
    }
    return instance;
}







/*  This is a wrapper for the left motor's SetPercent() function, and is meant to restrict control of that motor.
 *
 *  int speed - A number in the range [-100, 100] that determines the motor's output speed.
 */
void DriveBase::driveLeftMotor(int speed)
{
    leftMotor.SetPercent(speed);
}

/*  This is a wrapper for the right motor's SetPercent() function, and is meant to restrict control of that motor through one method.
 *
 *  int speed - A number in the range [-100, 100] that determines the motor's output speed.
 */
void DriveBase::driveRightMotor(int speed)
{
    rightMotor.SetPercent(speed);
}





/*  This is a wrapper for the left motor's stop function, and is meant to restrict control of that motor through one method.
 */
void DriveBase::stopLeftMotor()
{
    leftMotor.Stop();
}

/*  This is a wrapper for the left motor's stop function, and is meant to restrict control of that motor through one method.
 */
void DriveBase::stopRightMotor()
{
    rightMotor.Stop();
}
