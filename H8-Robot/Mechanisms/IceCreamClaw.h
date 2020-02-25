#ifndef ICECREAMCLAW_H
#define ICECREAMCLAW_H


class IceCreamClaw
{
public:
    IceCreamClaw();
    void setAngle(float);
    void setPosition(char);
    void touchCalibrateServo();
    void setEndStops();
};

extern IceCreamClaw iceCream;

#endif // ICECREAMCLAW_H
