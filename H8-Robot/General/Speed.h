#ifndef SPEED_H
#define SPEED_H


class Speed
{
public:
    Speed();

    int getCurrentFinishSpeed();
    int rampSpeed(double, int);
};

extern Speed speed;

#endif // SPEED_H
