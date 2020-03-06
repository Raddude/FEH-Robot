/*  BurgerFlipper.cpp
 *  Author: Jake Marchewitz
 *  Creation Date: 2/14/20
 *
 *  Purpose: This file is meant to house all methods and behaviors linked to the burger flipper.
 *
 *  Superclasses: None.
 *  Subclasses: None.
 *  Used in: None.
 */

#include <FEHServo.h>
#include "BurgerFlipper.h"

#define BURGER_SERVO_MIN 610
#define BURGER_SERVO_MAX 2260

BurgerFlipper burger;

FEHServo burgerServo(FEHServo::Servo0);







BurgerFlipper::BurgerFlipper()
{

}







/*  This is a wrapper for the SetDegree() function
 */
void BurgerFlipper::setAngle(float angle)
{
    burgerServo.SetDegree(angle);
}

/*  This method allows for easy selection of the vertical and both horizontal positions
 *
 *  char input - This char (L/U/R) represents the position of the servo
 */
void BurgerFlipper::setPosition(char input)
{
    if (input == 'L')
    {
        burgerServo.SetDegree(0.0);
    }

    else if (input == 'U')
    {
        burgerServo.SetDegree(93.0);
    }

    else if (input == 'F')
    {
        burgerServo.SetDegree(102.0);
    }

    else if (input == 'R')
    {
        burgerServo.SetDegree(180.0);
    }

    else
    {
        burgerServo.SetDegree(0.0);
    }
}





/*  This is a wrapper for the TouchCailbrate() function
 */
void BurgerFlipper::touchCalibrateServo()
{
    burgerServo.TouchCalibrate();
}

/*  This method manually sets the min and max values on startup. The values come from TouchCalibrate()
 */
void BurgerFlipper::setEndStops()
{
    burgerServo.SetMin(BURGER_SERVO_MIN);
    burgerServo.SetMax(BURGER_SERVO_MAX);
}
