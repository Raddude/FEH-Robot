#ifndef SCREENCONTROLLER_H
#define SCREENCONTROLLER_H

using namespace std;


class ScreenController
{
public:
    ScreenController();

    void clearScreen();
    void clearBuffer();

    void displayFullScreenMessage(const char*);
    void displayBatteryVoltage();

    void displayCdSReading();
    void displayCdSDetection();

    void displayLimitSwitchReadings();
    void displayLimitSwitchDetections();

    void displayOptosensorReading(char);
    void displayOptosensorDetection(char);

    void displayAllOptosensorReading();
    void displayAllOptosensorDetection();

    void displayEncoderCount(char);
    void displayEncoderDistance(char);

    void displayAllEncoderCounts();
    void displayAllEncoderDistances();

    void displayCurrentTime();
};

extern ScreenController screen;

#endif // SCREENCONTROLLER_H
