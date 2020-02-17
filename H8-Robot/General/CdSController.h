#ifndef CDSCONTROLLER_H
#define CDSCONTROLLER_H


class CdSController
{
public:
    CdSController();
    static CdSController* getInstance();

    bool isRed();
    bool isBlue();
    double getCurrentValue();

private:
    static CdSController *instance;
};

#endif // CDSCONTROLLER_H
