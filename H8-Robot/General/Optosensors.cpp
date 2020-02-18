/*  Optosensors.cpp
 *  Author: Jake Marchewitz
 *  Creation Date: 2/14/20
 *
 *  Purpose: This file is meant to house all methods and behaviors linked to the optosensors.
 *
 *  Superclasses: None.
 *  Subclasses: None.
 *  Used in: Commands.cpp, ScreenController.cpp.
 */

#include <FEHIO.h>
#include "Optosensors.h"

#define L_MIN_LINE_THRESHOLD 2.66
#define L_MAX_LINE_THRESHOLD 2.85
#define M_MIN_LINE_THRESHOLD 2.55
#define M_MAX_LINE_THRESHOLD 2.75
#define R_MIN_LINE_THRESHOLD 2.75
#define R_MAX_LINE_THRESHOLD 2.95

AnalogInputPin leftSensor(FEHIO::P1_2);
AnalogInputPin middleSensor(FEHIO::P1_1);
AnalogInputPin rightSensor(FEHIO::P1_0);

Optosensors optosensors;







Optosensors::Optosensors()
{

}







/*  This method returns the value of the left optosensor as a double
 */
double Optosensors::getLeftOptosensor()
{
    return leftSensor.Value();
}

/*  This method returns the value of the middle optosensor as a double
 */
double Optosensors::getMiddleOptosensor()
{
    return middleSensor.Value();
}

/*  This method returns the value of the right optosensor as a double
 */
double Optosensors::getRightOptosensor()
{
    return rightSensor.Value();
}





/*  This method returns if the left sensor is over a black line
 */
bool Optosensors::isLeftSeeingALine()
{
    if (leftSensor.Value() > L_MIN_LINE_THRESHOLD && leftSensor.Value() < L_MAX_LINE_THRESHOLD)
    {
        return true;
    }

    return false;
}

/*  This method returns if the middle sensor is over a black line
 */
bool Optosensors::isMiddleSeeingALine()
{
    if (middleSensor.Value() > M_MIN_LINE_THRESHOLD && middleSensor.Value() < M_MAX_LINE_THRESHOLD)
    {
        return true;
    }

    return false;
}

/*  This method returns if the right sensor is over a black line
 */
bool Optosensors::isRightSeeingALine()
{
    if (rightSensor.Value() > R_MIN_LINE_THRESHOLD && rightSensor.Value() < R_MAX_LINE_THRESHOLD)
    {
        return true;
    }

    return false;
}
