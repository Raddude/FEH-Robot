/*  LimitSwitches.cpp
 *  Author: Jake Marchewitz
 *  Creation Date: 2/14/20
 *
 *  Purpose: This file is meant to house all methods and behaviors linked to the limit switches (bump switches).
 *
 *  Superclasses: None.
 *  Subclasses: None.
 *  Used in: None.
 *  Uses: None.
 */

#include "LimitSwitches.h"

LimitSwitches* instance = new LimitSwitches();







LimitSwitches::LimitSwitches()
{

}

/*  This method returns the singleton instance of LimitSwitches.cpp
 */
LimitSwitches* LimitSwitches::getInstance()
{
    return instance;
}
