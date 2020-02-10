#include <FEHLCD.h>
#include <FEHUtility.h>
#include <FEHMotor.h>
#include <FEHIO.h>

#include "screencontroller.h"





int main(void)
{
    //Main variables
    float x,y;
    int timer = 0;

    //Singleton Instances
    ScreenController* screen = new ScreenController();



    //Wait message
    screen->clearScreen();
    screen->displayFullScreenMessage("WAIT...");



    //Wait to start until screen is touched and released
    while(!LCD.Touch(&x,&y))
    {}
    while(LCD.Touch(&x,&y))
    {}



    screen->clearScreen();
    screen->displayBatteryVoltage();



    return 0;
}
