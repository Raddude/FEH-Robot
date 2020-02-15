/*  IceCreamClaw.cpp
 *  Author: Jake Marchewitz
 *  Creation Date: 2/14/20
 *
 *  Purpose: This file is meant to house all methods and behaviors linked to the ice cream claw.
 *
 *  Superclasses: None.
 *  Subclasses: None.
 *  Used in: None.
 *  Uses: None.
 */

#include "IceCreamClaw.h"

IceCreamClaw* IceCreamClaw::instance = 0;







IceCreamClaw::IceCreamClaw()
{

}

/* This method returns the singleton instance of IceCreamClaw.cpp
 */
IceCreamClaw* IceCreamClaw::getInstance()
{
    if (instance == 0)
    {
        instance = new IceCreamClaw();
    }
    return instance;
}
