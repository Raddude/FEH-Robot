#ifndef CDSCONTROLLER_H
#define CDSCONTROLLER_H


class CdSController
{
public:
    CdSController();

    bool isRed();
    bool isBlue();
    double getCurrentValue();
};

extern CdSController cdsCell;

#endif // CDSCONTROLLER_H
