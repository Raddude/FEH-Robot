#ifndef SCREENCONTROLLER_H
#define SCREENCONTROLLER_H

#include <string.h>
#include "CdSController.h"
#include "Optosensors.h"

using namespace std;


class ScreenController
{
public:
    ScreenController();

    void clearScreen();

    void displayFullScreenMessage(const char*);
    void displayBatteryVoltage();
    void displayCdSReading();

    void displayOptosensorReading(char);
    void displayOptosensorDetection(char);

    void displayAllOptosensorReading();
    void displayAllOptosensorDetection();
};

extern ScreenController screen;

#endif // SCREENCONTROLLER_H
