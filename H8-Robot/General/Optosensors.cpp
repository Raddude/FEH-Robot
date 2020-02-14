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

AnalogInputPin leftSensor(FEHIO::P1_2);
AnalogInputPin middleSensor(FEHIO::P1_1);
AnalogInputPin rightSensor(FEHIO::P1_0);

Optosensors *instance = new Optosensors();







Optosensors::Optosensors()
{

}

/*  Returns the singleton instance of Optosensors.cpp
 */
Optosensors* Optosensors::getInstance()
{
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
