/*  MAIN.CPP
 *  Author: Jake Marchewitz
 *  Creation Date: 2/10/20
 *
 *  Purpose: This file is the hub for the robot's control system, and is the highest level class in the project. The main method is called regularly and often, and acts as an overview of the entire robot's function.
 *
 *  Superclasses: None.
 *  Subclasses: None.
 *  Used in: None.
 *  Uses: screen_controller.cpp, main_drive_controller.cpp.
 */

#include <FEHLCD.h>
#include <FEHUtility.h>
#include <FEHMotor.h>
#include <FEHIO.h>

#include "screen_controller.h"





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
