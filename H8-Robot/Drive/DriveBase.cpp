/*  DriveBase.cpp
 *  Author: Jake Marchewitz
 *  Creation Date: 2/10/20
 *
 *  Purpose: This file acts as a template for each half of the robot's drive control. The purpose of this structure is to account for the fact that the motors are mounted in opposite directions. The "drive forward 10 units" method for both sides will make the robot move forward 10 units, but the directions the motors will be turning are opposite.
 *
 *  Superclasses: None.
 *  Subclasses: LeftDrive.cpp, RightDrive.cpp.
 *  Used in: None.
 */

#include <FEHMotor.h>
#include <FEHIO.h>
#include <math.h>
#include "DriveBase.h"
#include "DriveConstants.h"

using namespace std;

DriveBase driveBase;

FEHMotor leftMotor(FEHMotor::Motor0, 9.0);
FEHMotor rightMotor(FEHMotor::Motor1, 9.0);

double areaSum;







DriveBase::DriveBase()
{

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





/*  This method shifts all of the previous values back by 1 slot, deletes the last value, and add the current value in the front
 *
 *  double currentValue - The current error value of the motor
 *  double* previousValues - A double array of previous error values
 */
void DriveBase::updatePreviousValues(double currentValue, double *previousValues)
{
    for (int i = driveConstants.getBufferSize(); i > 0; i--)
    {
        previousValues[i] = previousValues[i-1];
    }

    previousValues[0] = currentValue;

}

/*  Resets the previous error values array to all values of 0
 *
 *  double* previousValues - A double array of previous error values
 */
void DriveBase::resetPreviousValues(double *previousValues)
{
    for (int i = 0; i < driveConstants.getBufferSize(); i++)
    {
        previousValues[i] = 0;
    }
}





/*  This is the BIG boi, the base-level PID controller. It sets a motor's speed to an appropriate percent to get to the target setpoint
 *
 *  char side - This char corresponds to either the left or right motor
 *  int setpoint - A distance in INCHES corresponding to the target distance of the given motor
 *  double* previousValues - A double array of size [driveConstants.getBufferSize()]
 *  double kP - The coefficient for the P term of the PID loop
 *  double kI - The coefficient for the I term of the PID loop
 *  double kD - The coefficient for the D term of the PID loop
 */
void DriveBase::driveMotorPID(char side, int setpoint, double *previousValues, double kP, double kI, double kD)
{
    if (side == 'L')
    {
        leftMotor.SetPercent(
                    (kP * previousValues[driveConstants.getBufferSize()]) + (kI * getAreaOfValues(previousValues) + (kD * getSlopeOfValues(previousValues)))
                    );
    }

    else if (side == 'R')
    {
        //Copy from side == 'L' when working
        rightMotor.SetPercent(
                    (kP * previousValues[driveConstants.getBufferSize()]) + (kI * getAreaOfValues(previousValues) + (kD * getSlopeOfValues(previousValues)))
                    );
    }
}

/*  This is the BIG boi, the base-level PID controller. It sets a motor's speed to an appropriate percent to get to the target setpoint
 *
 *  char side - This char corresponds to either the left or right motor
 *  double setpoint - A distance in TICKS corresponding to the target distance of the given motor
 *  double* previousValues - A double array of size [driveConstants.getBufferSize()]
 *  double kP - The coefficient for the P term of the PID loop
 *  double kI - The coefficient for the I term of the PID loop
 *  double kD - The coefficient for the D term of the PID loop
 */
void DriveBase::driveMotorPID(char side, double setpoint, double *previousValues, double kP, double kI, double kD)
{
    driveMotorPID(side, setpoint * driveConstants.getDistancePerTick(), previousValues, kP, kI, kD);
}





/*  This function returns the area of the previous error values of a motor for PID. This is a manual Riemann sum where every value has a height of its value and a width of 1.
 *
 *  double *previousValues - The array of previous error values of the motor.
 */
double DriveBase::getAreaOfValues(double *previousValues)
{
    areaSum = 0;

    for (int i = 0; i < driveConstants.getBufferSize(); i++)
    {
        areaSum += previousValues[i];
    }

    return areaSum;
}

/*  This function returns the slope of the previous error values of a motor for PID. The values used to calculate slope are the current value and the one [driveConstants.getSLopeDomain()] before the current value
 *
 *  double *previousValues - The array of previous error values of the motor.
 */
double DriveBase::getSlopeOfValues(double *previousValues)
{
    return (previousValues[driveConstants.getBufferSize()] - previousValues[driveConstants.getBufferSize() - driveConstants.getSlopeDomain()])/(driveConstants.getSlopeDomain());
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
