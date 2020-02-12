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

LeftDrive* leftDrive = new LeftDrive();
RightDrive* rightDrive = new RightDrive();







MainDriveController::MainDriveController()
{

}







//Drive motors as the listed speeds. This is a generalized version of the specific methods that follow.
void MainDriveController::driveByPower(int leftSpeed, int rightSpeed)
{
    driveLeftCorrected(leftSpeed);
    driveRightCorrected(rightSpeed);
}



//Drive motors at the listed speeds to the desired distance
void MainDriveController::driveByEncoders(int target, int speed)
{


    if (leftDrive->getLeftEncoderDistance() < target)
    {
        leftDrive->driveLeftCorrected(speed);
    }

    else
    {
        leftDrive->stopLeftMotor();
    }



    if (rightDrive->getRightEncoderDistance() < target)
    {
        rightDrive->driveRightCorrected(speed);
    }

    else
    {
        rightDrive->stopRightMotor();
    }
}



//Go straight at the listed speed
void MainDriveController::goStraight(int speed)
{
    driveByPower(speed, speed);
}

//Turn left at the listed speed
void MainDriveController::turnLeft(int speed)
{
    driveByPower(-speed, speed);
}

//Turn right at the listed speed
void MainDriveController::turnRight(int speed)
{
    driveByPower(speed, -speed);
}



//Stop motors
void MainDriveController::stopMotors()
{
    LeftDrive::stopLeftMotor();
    RightDrive::stopRightMotor();
}
