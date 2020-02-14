/*  DriveConstants.cpp
 *  Author: Jake Marchewitz
 *  Creation Date: 2/12/20
 *
 *  Purpose: This file acts as a central location for important drive constants such as wheel diameter and distance covered per encoder tick.
 *
 *  Superclasses: None.
 *  Subclasses: None.
 *  Used in: Main.cpp, MainDriveController.cpp, LeftDrive.cpp, RightDrive.cpp.
 *  Uses: None.
 */

#include "DriveConstants.h"

#define WHEEL_DIAMETER 2.5
#define WHEEL_SPAN 6.875 //This is the distance between the center of the contact points of both wheels, std 6.875
#define TICKS_PER_ROTATION 318
#define PI 3.141592653589793238463
#define DISTANCE_PER_ROTATION (PI*WHEEL_DIAMETER)
#define DISTANCE_PER_TICK (DISTANCE_PER_ROTATION/TICKS_PER_ROTATION)
#define DISTANCE_PER_FULL_TURN (PI*WHEEL_SPAN)
#define TICKS_PER_FULL_TURN (DISTANCE_PER_TICK/DISTANCE_PER_FULL_TURN)
#define SLEEP_AMOUNT 0.125

DriveConstants* instance = new DriveConstants();







DriveConstants::DriveConstants()
{

}

/*  This method returns the singleton instance of DriveConstants.cpp
 */
DriveConstants* DriveConstants::getInstance()
{
    return instance;
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

/*  This method returns the default sleep duration between actions
 */
double DriveConstants::getSleepAmount()
{
    return SLEEP_AMOUNT;
}
