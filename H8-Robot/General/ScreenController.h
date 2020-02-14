#ifndef SCREENCONTROLLER_H
#define SCREENCONTROLLER_H

#include <string.h>

using namespace std;


class ScreenController
{
public:
    ScreenController();
    ScreenController* getInstance();
    void clearScreen();
    void displayFullScreenMessage(const char*);
    void displayBatteryVoltage();
};

#endif // SCREENCONTROLLER_H
