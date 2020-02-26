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

#include "Speed.h"
#include "Time.h"

Speed speed;

int finishSpeed;







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
 */
int Speed::rampSpeed(double runTime, int topSpeed)
{

}
