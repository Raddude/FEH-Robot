/*  Optosensors.cpp
 *  Author: Jake Marchewitz
 *  Creation Date: 2/14/20
 *
 *  Purpose: This file is meant to house all methods and behaviors linked to the optosensors.
 *
 *  Superclasses: None.
 *  Subclasses: None.
 *  Used in: main.cpp.
 *  Uses: None.
 */

#include <FEHIO.h>
#include "Optosensors.h"

#define MIN_LINE_THRESHOLD 0
#define MAX_LINE_THRESHOLD 3.3

AnalogInputPin leftSensor(FEHIO::P1_2);
AnalogInputPin middleSensor(FEHIO::P1_1);
AnalogInputPin rightSensor(FEHIO::P1_0);

Optosensors* Optosensors::instance = 0;







Optosensors::Optosensors()
{

}

/*  Returns the singleton instance of Optosensors.cpp
 */
Optosensors* Optosensors::getInstance()
{
    if (instance == 0)
    {
        instance = new Optosensors();
    }
    return instance;
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
    if (leftSensor.Value() > MIN_LINE_THRESHOLD && leftSensor.Value() < MAX_LINE_THRESHOLD)
    {
        return true;
    }

    return false;
}

/*  This method returns if the middle sensor is over a black line
 */
bool Optosensors::isMiddleSeeingALine()
{
    if (middleSensor.Value() > MIN_LINE_THRESHOLD && middleSensor.Value() < MAX_LINE_THRESHOLD)
    {
        return true;
    }

    return false;
}

/*  This method returns if the right sensor is over a black line
 */
bool Optosensors::isRightSeeingALine()
{
    if (rightSensor.Value() > MIN_LINE_THRESHOLD && rightSensor.Value() < MAX_LINE_THRESHOLD)
    {
        return true;
    }

    return false;
}
