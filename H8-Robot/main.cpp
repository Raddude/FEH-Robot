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
    ScreenController screen = new ScreenController();



    screen.clearScreen();



    //Wait to start until screen is touched and released
    while(!LCD.Touch(&x,&y))
    {}
    while(LCD.Touch(&x,&y))
    {}

    LCD.WriteLine("B");

    return 0;
}
