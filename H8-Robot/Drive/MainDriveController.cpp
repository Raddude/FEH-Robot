/*  MainDriveController.cpp
 *  Author: Jake Marchewitz
 *  Creation Date: 2/10/20
 *
 *  Purpose: This class unifies the two halves of the robot into one file and is the highest level drive class. This class directly interfaces with main.cpp and wraps a lot of functionality into easy to use, high level methods.
 *
 *  Superclasses: LeftDrive.cpp, RightDrive.cpp.
 *  Subclasses: None.
 *  Used in: main.cpp.
 *  Uses: None.
 */

#include <FEHUtility.h>
#include "General/Time.h"
#include "DriveConstants.h"
#include "MainDriveController.h"
#include "Commands.h"

#define SLEEP_AMOUNT 0.25

using namespace std;

MainDriveController drive;
double leftDistanceFromTurn, rightDistanceFromTurn, leftOrbitCircumference, rightOrbitCircumference;
int closeSpeed;







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
bool MainDriveController::driveByEncodersUncorrected(double target, int speed)
{
    return driveByEncodersUncorrected(target, speed, target, speed);
}

/*  This overloaded method drives each half of the robot to its own distance at its own speed.
 *
 *  double leftTarget - A distance in INCHES of how far the left half of the robot should travel.
 *  int leftSpeed - The percent speed of the left motor on the interval [-100. 100]. Positive is 'forwards', since the direction is corrected for by the driveLeftCorrected() method.
 *  double rightTarget - A distance in INCHES of how far the right half of robot should travel.
 *  int rightSpeed - The percent speed of the right motor on the interval [-100. 100]. Positive is 'forwards', since the direction is corrected for by the driveRightCorrected() method.
 */
bool MainDriveController::driveByEncodersUncorrected(double leftTarget, int leftSpeed, double rightTarget, int rightSpeed)
{
    if (LeftDrive::getLeftEncoderDistance() < leftTarget)
    {
        LeftDrive::driveLeftCorrected(leftSpeed);
    }

    else
    {
        commands.postMoveReset();
        return false;
    }



    if (RightDrive::getRightEncoderDistance() < rightTarget)
    {
        RightDrive::driveRightCorrected(rightSpeed);
    }

    else
    {
        commands.postMoveReset();
        return false;
    }

    return true;
}

/*  This overloaded method drives each half of the robot to its own distance at its own speed.
 *
 *  int leftTarget - A distance in TICKS of how far the left half of the robot should travel.
 *  int leftSpeed - The percent speed of the left motor on the interval [-100. 100]. Positive is 'forwards', since the direction is corrected for by the driveLeftCorrected() method.
 *  int rightTarget - A distance in TICKS of how far the right half of robot should travel.
 *  int rightSpeed - The percent speed of the right motor on the interval [-100. 100]. Positive is 'forwards', since the direction is corrected for by the driveRightCorrected() method.
 */
bool MainDriveController::driveByEncodersUncorrected(int leftTarget, int leftSpeed, int rightTarget, int rightSpeed)
{
    return driveByEncodersUncorrected(leftTarget * driveConstants.getDistancePerTick(), leftSpeed, rightTarget * driveConstants.getDistancePerTick(), rightSpeed);
}

/*  This overloaded method drives each half of the robot to its own distance at its own speed.
 *
 *  double leftTarget - A distance in INCHES of how far the left half of the robot should travel.
 *  int leftSpeed - The percent speed of the left motor on the interval [-100. 100]. Positive is 'forwards', since the direction is corrected for by the driveLeftCorrected() method.
 *  double rightTarget - A distance in INCHES of how far the right half of robot should travel.
 *  int rightSpeed - The percent speed of the right motor on the interval [-100. 100]. Positive is 'forwards', since the direction is corrected for by the driveRightCorrected() method.
 */
bool MainDriveController::driveByEncoders(double leftTarget, int leftSpeed, double rightTarget, int rightSpeed)
{
    leftTarget = leftTarget - (driveConstants.getOvershootTicks('L', leftSpeed) * driveConstants.getDistancePerTick());
    rightTarget = rightTarget - (driveConstants.getOvershootTicks('R', rightSpeed) * driveConstants.getDistancePerTick());

    return driveByEncodersUncorrected(leftTarget, leftSpeed, rightTarget, rightSpeed);
}

/*  This overloaded method drives the robot forward to the target distance at the listed speed.
 *
 *  double target - A distance in INCHES of how far the robot should travel.
 *  int speed - The percent speed of both motors on the interval [-100. 100]. Positive is 'forwards', since the direction is corrected for by the driveLeftCorrected() and driveRightCorrected() methods.
 */
bool MainDriveController::driveByEncoders(double target, int speed)
{
    return driveByEncoders(target, speed, target, speed);
}



/*  This overloaded method drives the robot forward to the target distance using PID
 *
 *  double target - A distance in INCHES that the robot must drive forward
 */
bool MainDriveController::driveByPID(double target)
{
    return driveByPID(target, target);
}

/*  This overloaded method drives the robot forward to the target distance using PID
 *
 *  double leftTarget - A distance in INCHES that the left half of the robot must travel
 *  double rightTarget - A distance in INCHES that the right half of the robot must travel
 */
bool MainDriveController::driveByPID(double leftTarget, double rightTarget)
{

    //If BOTH encoders are within the error margin
    if (LeftDrive::getLeftEncoderDistance() >= leftTarget - driveConstants.getPIDErrorMargin() && LeftDrive::getLeftEncoderDistance() <= leftTarget + driveConstants.getPIDErrorMargin())
    {
        if (RightDrive::getRightEncoderDistance() >= rightTarget - driveConstants.getPIDErrorMargin() && RightDrive::getRightEncoderDistance() <= rightTarget + driveConstants.getPIDErrorMargin())
        {
            resetPID();
            time.sleepStandard();
            return false;
        }
    }


    LeftDrive::driveLeftPID(leftTarget);
    RightDrive::driveRightPID(rightTarget);

    return true;
}





/*  This method resets the robot for a different setpoint
 */
void MainDriveController::resetPID()
{
    LeftDrive::resetLeftErrorValues();
    RightDrive::resetRightErrorValues();

    LeftDrive::resetLeftEncoder();
    RightDrive::resetRightEncoder();
}





/*  This method has the robot make a 90 degree left turn about the center of rotation.
 *
 *  double angle - The angle in DEGREES that the robot should turn left.
 *  int speed - The speed at which the turn is executed, on a scale of [0, 100].
 */
bool MainDriveController::turnLeft(double angle, int speed)
{
    return driveByEncoders((angle/360) * driveConstants.getDistancePerFullTurn(), -speed, (angle/360) * driveConstants.getDistancePerFullTurn(), speed);
}

/*  This method has the robot make a 90 degree right turn about the center of rotation.
 *
 *  double angle - The angle in DEGREES that the robot should turn right.
 *  int speed - The speed at which the turn is executed, on a scale of [0, 100].
 */
bool MainDriveController::turnRight(double angle, int speed)
{
    return driveByEncoders((angle/360) * driveConstants.getDistancePerFullTurn(), speed, (angle/360) * driveConstants.getDistancePerFullTurn(), -speed);
}





/*  This method only turns half of the robot, to pivot around the other wheel
 *
 *  double angle - The angle the robot must turn left towards
 *  int speed - A speed on the interval [-100, 100] for the motors to turn
 */
bool MainDriveController::pivotLeft(double angle, int speed)
{
    return driveByEncoders(2000, 0, (2*angle/360) * driveConstants.getDistancePerFullTurn(), speed);
}

/*  This method only turns half of the robot, to pivot around the other wheel
 *
 *  double angle - The angle the robot must turn left towards
 *  int speed - A speed on the interval [-100, 100] for the motors to turn
 */
bool MainDriveController::pivotRight(double angle, int speed)
{
    return driveByEncoders((2*angle/360) * driveConstants.getDistancePerFullTurn(), speed, 2000, 0);
}





/*  This method has the robot turn about a point that is neither in the center nor under a wheel. This allows for more turning options
 *
 *  double angle - The angle that the robot will cover out of a full circle orbiting this radius
 *  int farSpeed - The speed of the far (right) side of the robot. The left speed will be calculated in relation to this.
 *  double radiusFromCenter - The distance away from the centerline of the robot that the robot will orbit about
 */
bool MainDriveController::orbitLeft(double angle, int farSpeed, double radiusFromCenter)
{
    leftDistanceFromTurn = radiusFromCenter - (driveConstants.getWheelSpan()/2);
    rightDistanceFromTurn = radiusFromCenter + (driveConstants.getWheelSpan()/2);

    leftOrbitCircumference = driveConstants.getPI() * 2 * leftDistanceFromTurn;
    rightOrbitCircumference = driveConstants.getPI() * 2 * rightDistanceFromTurn;

    closeSpeed = farSpeed * (leftDistanceFromTurn/rightDistanceFromTurn);

    driveByEncoders((angle/360) * leftOrbitCircumference, closeSpeed, (angle/360) * rightOrbitCircumference, farSpeed);
}

/*  This method has the robot turn about a point that is neither in the center nor under a wheel. This allows for more turning options
 *
 *  double angle - The angle that the robot will cover out of a full circle orbiting this radius
 *  int farSpeed - The speed of the far (right) side of the robot. The left speed will be calculated in relation to this.
 *  double radiusFromCenter - The distance away from the centerline of the robot that the robot will orbit about
 */
bool MainDriveController::orbitRight(double angle, int farSpeed, double radiusFromCenter)
{
    leftDistanceFromTurn = radiusFromCenter + (driveConstants.getWheelSpan()/2);
    rightDistanceFromTurn = radiusFromCenter - (driveConstants.getWheelSpan()/2);

    leftOrbitCircumference = driveConstants.getPI() * 2 * leftDistanceFromTurn;
    rightOrbitCircumference = driveConstants.getPI() * 2 * rightDistanceFromTurn;

    closeSpeed = farSpeed * (rightDistanceFromTurn/leftDistanceFromTurn);

    driveByEncoders((angle/360) * leftOrbitCircumference, farSpeed, (angle/360) * rightOrbitCircumference, closeSpeed);
}





/*  This method returns the number of ticks required to move one wheel the given distance
 *
 *  double distance - The distance in INCHES to be converted into ticks
 */
double MainDriveController::getTickCountFromDistance(double distance)
{
    return distance * LeftDrive::getDistancePerTick();
}

/*  This method returns the number of ticks required on both sides of the robot to turn the robot the given angle
 *
 *  double angle - The angle in DEGREES to be converted to ticks
 */
double MainDriveController::getDistanceFromAngle(double angle)
{
    return (angle/360) * LeftDrive::getDistancePerFullTurn();
}





/*  This method stops both motors.
 */
void MainDriveController::stopMotors()
{
    LeftDrive::stopLeftMotor();
    RightDrive::stopRightMotor();
}

/*  This method resets both encoders.
 */
void MainDriveController::resetEncoders()
{
    LeftDrive::resetLeftEncoder();
    RightDrive::resetRightEncoder();
}
