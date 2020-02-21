#ifndef BURGERFLIPPER_H
#define BURGERFLIPPER_H


class BurgerFlipper
{
public:
    BurgerFlipper();
    void setAngle(float);
    void setPosition(char);
    void touchCalibrateServo();
    void setEndStops();
};

extern BurgerFlipper burger;

#endif // BURGERFLIPPER_H
