#ifndef RPSManager_H
#define RPSManager_H


class RPSManager
{
public:
    RPSManager();

    void initializeTouchMenu();
    void initializeMenu();

    double getX();
    double getY();
    double getHeading();

    int timeRemaining();
    char currentCourse();
    char currentRegionLetter();
    int currentRegion();

    char getIceCream();
};

extern RPSManager rps;

#endif // RPS_H
