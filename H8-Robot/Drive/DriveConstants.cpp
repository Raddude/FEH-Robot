/*  DriveConstants.cpp
 *  Author: Jake Marchewitz
 *  Creation Date: 2/12/20
 *
 *  Purpose: This file acts as a central location for important drive constants such as wheel diameter and distance covered per encoder tick.
 *
 *  Superclasses: None.
 *  Subclasses: None.
 *  Used in: Main.cpp, MainDriveController.cpp, LeftDrive.cpp, RightDrive.cpp.
 */

#include <cmath>
#include "DriveConstants.h"

#define WHEEL_DIAMETER 3
#define WHEEL_SPAN 8.125  //7.925 is the default value configured at 360 degrees
#define TICKS_PER_ROTATION 318
#define PI 3.141592653589793238463
#define DISTANCE_PER_ROTATION (PI*WHEEL_DIAMETER)
#define DISTANCE_PER_TICK (DISTANCE_PER_ROTATION/TICKS_PER_ROTATION)
#define DISTANCE_PER_FULL_TURN (PI*WHEEL_SPAN)
#define TICKS_PER_FULL_TURN (DISTANCE_PER_TICK/DISTANCE_PER_FULL_TURN)

#define L_OVERSHOOT_A 0.0071
#define L_OVERSHOOT_B 0.2854
#define L_OVERSHOOT_C 1.5155
#define R_OVERSHOOT_A 0.0056
#define R_OVERSHOOT_B 0.4716
#define R_OVERSHOOT_C 4.2678


//PID Constants
#define L_KP 1
#define L_KI 0
#define L_KD 0
#define R_KP 1
#define R_KI 0
#define R_KD 0
#define BUFFER_SIZE 25
#define KD_SLOPE_DOMAIN 5
#define PID_ERROR_MARGIN 0.125 //Distance in inches, range that PID can be off by

DriveConstants driveConstants;







DriveConstants::DriveConstants()
{

}







/*  This method returns the wheel diameter in inches.
 */
double DriveConstants::getWheelDiameter()
{
    return WHEEL_DIAMETER;
}

/*  This method returns the wheel span in inches.
 */
double DriveConstants::getWheelSpan()
{
    return WHEEL_SPAN;
}

/*  This method returns ticks per rotation.
 */
double DriveConstants::getTicksPerRotation()
{
    return TICKS_PER_ROTATION;
}

/*  This method returns the value of PI.
 */
double DriveConstants::getPI()
{
    return PI;
}

/*  This method returns the distance travelled per wheel rotation in INCHES.
 */
double DriveConstants::getDistancePerRotation()
{
    return DISTANCE_PER_ROTATION;
}

/*  This method returns the distance travelled per encoder tick in INCHES.
 */
double DriveConstants::getDistancePerTick()
{
    return DISTANCE_PER_TICK;
}

/*  This method returns the distance travelled per full 360 degree turn of the robot in INCHES.
 */
double DriveConstants::getDistancePerFullTurn()
{
    return DISTANCE_PER_FULL_TURN;
}

/*  This method returns the number of encoder ticks per full 360 degree turn of the robot.
 */
double DriveConstants::getTicksPerFullTurn()
{
    return TICKS_PER_FULL_TURN;
}

/*  This method returns the number of ticks that the encoders typically overshoot by at a given speed
 *
 *  int speed - The motor speed that the robot is travelling at in the range of [0, 100>]
 */
int DriveConstants::getOvershootTicks(char side, int speed)
{
    if (side == 'L')
    {
        return L_OVERSHOOT_A * speed * speed + L_OVERSHOOT_B * speed + L_OVERSHOOT_C;
    }

    else if (side == 'R')
    {
        return R_OVERSHOOT_A * speed * speed + R_OVERSHOOT_B * speed + R_OVERSHOOT_C;
    }
}




/*  This method returns the P coefficient for the listed side's PID loop
 *
 *  char side - The side of the robot that is being used in PID
 */
double DriveConstants::getKP(char side)
{
    if (side == 'L')
    {
        return L_KP;
    }

    else if (side == 'R')
    {
        return R_KP;
    }

    return 0;
}

/*  This method returns the I coefficient for the listed side's PID loop
 *
 *  char side - The side of the robot that is being used in PID
 */
double DriveConstants::getKI(char side)
{
    if (side == 'L')
    {
        return L_KI;
    }

    else if (side == 'R')
    {
        return R_KI;
    }

    return 0;
}

/*  This method returns the D coefficient for the listed side's PID loop
 *
 *  char side - The side of the robot that is being used in PID
 */
double DriveConstants::getKD(char side)
{
    if (side == 'L')
    {
        return L_KD;
    }

    else if (side == 'R')
    {
        return R_KD;
    }

    return 0;
}

/*  This method returns the size of the PID buffer, the number of previous values stored in memory
 */
int DriveConstants::getBufferSize()
{
    return BUFFER_SIZE;
}

/*  This method returns the distance between previous values used to calculate the current D term
 */
int DriveConstants::getSlopeDomain()
{
    return KD_SLOPE_DOMAIN;
}

/*  This method returns the margin of error for PID
 */
double DriveConstants::getPIDErrorMargin()
{
    return PID_ERROR_MARGIN;
}
