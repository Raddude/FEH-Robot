/*  LimitSwitches.cpp
 *  Author: Jake Marchewitz
 *  Creation Date: 2/14/20
 *
 *  Purpose: This file is meant to house all methods and behaviors linked to the limit switches (bump switches).
 *
 *  Superclasses: None.
 *  Subclasses: None.
 *  Used in: None.
 */

#include <FEHIO.h>
#include "LimitSwitches.h"

LimitSwitches limitSwitches;

DigitalInputPin backBumpSwitch(FEHIO::P2_1);
DigitalInputPin leftBumpSwitch(FEHIO::P2_2);
DigitalInputPin rightBumpSwitch(FEHIO::P2_3);







LimitSwitches::LimitSwitches()
{

}







/*  This returns the state of the back limit switch
 */
double LimitSwitches::getBackLimitSwitchReading()
{
    return backBumpSwitch.Value();
}

/*  This returns the detection of the back limit switch
 */
bool LimitSwitches::isBackLimitSwitchPressed()
{
    if (backBumpSwitch.Value() == 0)
    {
        return true;
    }

    return false;
}
