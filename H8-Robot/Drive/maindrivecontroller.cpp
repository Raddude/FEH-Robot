/*  MainDriveController.cpp
 *  Author: Jake Marchewitz
 *  Creation Date: 2/10/20
 *
 *  Purpose: This class unifies the two halves of the robot into one file and is the highest level drive class. This class directly interfaces with main.cpp and wraps a lot of functionality into easy to use, high level methods.
 *
 *  Superclasses: None.
 *  Subclasses: None.
 *  Used in: main.cpp.
 *  Uses: LeftDrive.cpp, RightDrive.cpp.
 */

#include "maindrivecontroller.h"
#include "leftdrive.h"
#include "rightdrive.h"







MainDriveController::MainDriveController()
{

}







//Drive motors as the listed speeds. This is a generalized version of the specific methods that follow.
void MainDriveController::driveMotors(int leftSpeed, int rightSpeed)
{
    driveLeftCorrected(leftSpeed);
    driveRightCorrected(rightSpeed);
}



//Go straight at the listed speed
void MainDriveController::goStraight(int speed)
{
    driveMotors(speed, speed);
}

//Turn left at the listed speed
void MainDriveController::turnLeft(int speed)
{
    driveMotors(-speed, speed);
}

//Turn right at the listed speed
void MainDriveController::turnRight(int speed)
{
    driveMotors(speed, -speed);
}



//Stop motors
void MainDriveController::stopMotors()
{
    LeftDrive::stopLeftMotor();
    RightDrive::stopRightMotor();
}
