#ifndef TICKETSLIDER_H
#define TICKETSLIDER_H


class TicketSlider
{
public:
    TicketSlider();
    void setAngle(float);
    void setPosition(char);
    void touchCalibrateServo();
    void setEndStops();
};

extern TicketSlider ticketSlider;

#endif // TICKETSLIDER_H
