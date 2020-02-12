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

#define RIGHT_ANGLE_TURN_DISTANCE 0 //Determine through testing

using namespace std;







MainDriveController::MainDriveController()
{

}







/*  This method directly drives the motors by setting each motor to run at the listed speed.
 *
 *  int leftSpeed - The percent speed of the left motor from [-100, 100]. Positive is 'forwards' for the robot, as the input's direction is corrected by driveLeftCorrected().
 *  int rightSpeed - The percent speed of the right motor from [-100, 100]. Positive is 'forwards' for the robot, as the input's direction is corrected by driveRightCorrected().
 */
void MainDriveController::driveByPower(int leftSpeed, int rightSpeed)
{
    driveLeftCorrected(leftSpeed);
    driveRightCorrected(rightSpeed);
}





/*  This overloaded method drives the robot forward to the target distance at the listed speed.
 *
 *  double target - A distance in INCHES of how far the robot should travel.
 *  int speed - The percent speed of both motors on the interval [-100. 100]. Positive is 'forwards', since the direction is corrected for by the driveLeftCorrected() and driveRightCorrected() methods.
 */
void MainDriveController::driveByEncoders(double target, int speed)
{


    if (LeftDrive::getLeftEncoderDistance() < target)
    {
        LeftDrive::driveLeftCorrected(speed);
    }

    else
    {
        LeftDrive::stopLeftMotor();
    }



    if (RightDrive::getRightEncoderDistance() < target)
    {
        RightDrive::driveRightCorrected(speed);
    }

    else
    {
        RightDrive::stopRightMotor();
    }
}

/*  This overloaded method drives each half of the robot to its own distance at its own speed.
 *
 *  double leftTarget - A distance in INCHES of how far the left half of the robot should travel.
 *  int leftSpeed - The percent speed of the left motor on the interval [-100. 100]. Positive is 'forwards', since the direction is corrected for by the driveLeftCorrected() method.
 *  double rightTarget - A distance in INCHES of how far the right half of robot should travel.
 *  int rightSpeed - The percent speed of the right motor on the interval [-100. 100]. Positive is 'forwards', since the direction is corrected for by the driveRightCorrected() method.
 */
void MainDriveController::driveByEncoders(double leftTarget, int leftSpeed, double rightTarget, int rightSpeed)
{


    if (LeftDrive::getLeftEncoderDistance() < leftTarget)
    {
        LeftDrive::driveLeftCorrected(leftSpeed);
    }

    else
    {
        LeftDrive::stopLeftMotor();
    }



    if (RightDrive::getRightEncoderDistance() < rightTarget)
    {
        RightDrive::driveRightCorrected(rightSpeed);
    }

    else
    {
        RightDrive::stopRightMotor();
    }
}





/*  This method has the robot make a 90 degree left turn about the center of rotation
 *
 *  int speed - The speed at which the turn is executed, on a scale of [0, 100]
 */
void MainDriveController::turnLeft(int speed)
{
    driveByEncoders(-RIGHT_ANGLE_TURN_DISTANCE, -speed, RIGHT_ANGLE_TURN_DISTANCE, speed);
}

/*  This method has the robot make a 90 degree right turn about the center of rotation
 *
 *  int speed - The speed at which the turn is executed, on a scale of [0, 100]
 */
void MainDriveController::turnRight(int speed)
{
    driveByEncoders(RIGHT_ANGLE_TURN_DISTANCE, speed, -RIGHT_ANGLE_TURN_DISTANCE, -speed);
}



/*  This method stops both motors.
 */
void MainDriveController::stopMotors()
{
    LeftDrive::stopLeftMotor();
    RightDrive::stopRightMotor();
}
