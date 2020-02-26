/*  Speed.cpp
 *  Author: Jake Marchewitz
 *  Creation Date: 2/25/20
 *
 *  Purpose: This file stores all methods relating to the robot speed, gives greater control over acceleration and braking
 *
 *  Superclasses: None.
 *  Subclasses: None.
 *  Used in: main.cpp.
 */

#include "Drive/MainDriveController.h"
#include "Speed.h"
#include "Time.h"

Speed speed;

int finishSpeed;
double completePercent, rampSlope;







Speed::Speed()
{

}







/*  This method returns the currently set final speed for overshoot calculations in other parts of the code.
 */
int Speed::getCurrentFinishSpeed()
{
    return finishSpeed;
}





/*  This function ramps the speed up and down to smooth the travel of the robot
 *
 *  double distance - The total distance of the command that rampSpeed() is being put into
 *  int topSpeed - The maximum speed that the robot should reach
 */
int Speed::rampSpeed(double distance, int topSpeed)
{
    finishSpeed = 20;
    completePercent = leftDrive.getLeftEncoderDistance()/distance;
    rampSlope = (topSpeed-finishSpeed) / 0.1;

    if (completePercent < 0.1)
    {
        return rampSlope * completePercent + 20;
    }

    else if (completePercent > 0.9)
    {
        return -rampSlope * (completePercent - 0.9) + topSpeed;
    }

    else
    {
        return topSpeed;
    }

}
