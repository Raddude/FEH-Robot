#ifndef LIMITSWITCHES_H
#define LIMITSWITCHES_H


class LimitSwitches
{
public:
    LimitSwitches();
    double getBackLimitSwitchReading();
    bool isBackLimitSwitchPressed();
};

extern LimitSwitches limitSwitches;

#endif // LIMITSWITCHES_H
