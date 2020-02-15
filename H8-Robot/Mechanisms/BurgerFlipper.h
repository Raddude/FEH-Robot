#ifndef BURGERFLIPPER_H
#define BURGERFLIPPER_H


class BurgerFlipper
{
public:
    BurgerFlipper();
    static BurgerFlipper* getInstance();

private:
    static BurgerFlipper *instance;
};

#endif // BURGERFLIPPER_H
