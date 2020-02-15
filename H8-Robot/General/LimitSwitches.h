#ifndef LIMITSWITCHES_H
#define LIMITSWITCHES_H


class LimitSwitches
{
public:
    LimitSwitches();
    static LimitSwitches* getInstance();

private:
    static LimitSwitches *instance;
};

#endif // LIMITSWITCHES_H
