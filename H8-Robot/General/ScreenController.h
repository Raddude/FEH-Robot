#ifndef SCREENCONTROLLER_H
#define SCREENCONTROLLER_H

#include <string.h>

using namespace std;


class ScreenController
{
public:
    ScreenController();
    static ScreenController* getInstance();
    void clearScreen();
    void displayFullScreenMessage(const char*);
    void displayBatteryVoltage();

private:
    static ScreenController *instance;
};

#endif // SCREENCONTROLLER_H
