/*  BurgerFlipper.cpp
 *  Author: Jake Marchewitz
 *  Creation Date: 2/14/20
 *
 *  Purpose: This file is meant to house all methods and behaviors linked to the burger flipper.
 *
 *  Superclasses: None.
 *  Subclasses: None.
 *  Used in: None.
 *  Uses: None.
 */

#include <FEHServo.h>
#include "BurgerFlipper.h"

BurgerFlipper* BurgerFlipper::instance = 0;







BurgerFlipper::BurgerFlipper()
{

}

/*  This method returns the singleton instance of BurgerFlipper.cpp
 */
BurgerFlipper* BurgerFlipper::getInstance()
{
    if (instance == 0)
    {
        instance = new BurgerFlipper();
    }
    return instance;
}
