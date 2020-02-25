/*  IceCreamClaw.cpp
 *  Author: Jake Marchewitz
 *  Creation Date: 2/14/20
 *
 *  Purpose: This file is meant to house all methods and behaviors linked to the ice cream claw.
 *
 *  Superclasses: None.
 *  Subclasses: None.
 *  Used in: None.
 */

#include <FEHServo.h>
#include "IceCreamClaw.h"

#define CLAW_SERVO_MIN 800
#define CLAW_SERVO_MAX 2400

IceCreamClaw iceCream;

FEHServo clawServo(FEHServo::Servo1);







IceCreamClaw::IceCreamClaw()
{

}






/*  This is a wrapper for the SetDegree() function
 */
void IceCreamClaw::setAngle(float angle)
{
    clawServo.SetDegree(angle);
}

/*  This method allows for easy selection of the vertical and both horizontal positions
 *
 *  char input - This char (L/U/R) represents the position of the servo
 */
void IceCreamClaw::setPosition(char input)
{
    if (input == 'L')
    {
        clawServo.SetDegree(0.0);
    }

    else if (input == 'U')
    {
        clawServo.SetDegree(93.0);
    }

    else if (input == 'R')
    {
        clawServo.SetDegree(180.0);
    }

    else
    {
        clawServo.SetDegree(0.0);
    }
}





/*  This is a wrapper for the TouchCailbrate() function
 */
void IceCreamClaw::touchCalibrateServo()
{
    clawServo.TouchCalibrate();
}

/*  This method manually sets the min and max values on startup. The values come from TouchCalibrate()
 */
void IceCreamClaw::setEndStops()
{
    clawServo.SetMin(CLAW_SERVO_MIN);
    clawServo.SetMax(CLAW_SERVO_MAX);
}
