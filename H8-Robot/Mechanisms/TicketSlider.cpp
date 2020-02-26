/*  TicketSlider.cpp
 *  Author: Jake Marchewitz
 *  Creation Date: 2/25/20
 *
 *  Purpose: This file is meant to house all methods and behaviors linked to the ticket slider arm.
 *
 *  Superclasses: None.
 *  Subclasses: None.
 *  Used in: None.
 */

#include <FEHServo.h>
#include "TicketSlider.h"

#define TICKET_SERVO_MIN 500
#define TICKET_SERVO_MAX 2400

TicketSlider ticketSlider;

FEHServo ticketServo(FEHServo::Servo2);







TicketSlider::TicketSlider()
{

}







/*  This is a wrapper for the SetDegree() function
 */
void TicketSlider::setAngle(float angle)
{
    ticketServo.SetDegree(angle);
}

/*  This method allows for easy selection of the vertical and both horizontal positions
 *
 *  char input - This char (L/U/R) represents the position of the servo
 */
void TicketSlider::setPosition(char input)
{
    if (input == 'U')
    {
        ticketServo.SetDegree(0.0);
    }

    else if (input == 'M')
    {
        ticketServo.SetDegree(35.0);
    }

    else if (input == 'D')
    {
        ticketServo.SetDegree(65.0);
    }

    else
    {
        ticketServo.SetDegree(0.0);
    }
}





/*  This is a wrapper for the TouchCailbrate() function
 */
void TicketSlider::touchCalibrateServo()
{
    ticketServo.TouchCalibrate();
}

/*  This method manually sets the min and max values on startup. The values come from TouchCalibrate()
 */
void TicketSlider::setEndStops()
{
    ticketServo.SetMin(TICKET_SERVO_MIN);
    ticketServo.SetMax(TICKET_SERVO_MAX);
}
