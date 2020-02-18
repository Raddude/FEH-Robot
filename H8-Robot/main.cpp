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
#include <string>
#include <iostream>

#include "General/CdSController.h"
#include "General/FileManager.h"
#include "General/ScreenController.h"
#include "General/Optosensors.h"
#include "Drive/MainDriveController.h"
#include "Drive/DriveConstants.h"
#include "Commands.h"

#define TEST_MOTOR_SPEED 30

using namespace std;

void gotoCorrectStartingCondition(char);







int main(void)
{
    /*  TO-DO LIST
     *
     * -Timer class, that constantly counts up and manages time
     * -Speed functions relating to time, that take in time and output speeds at different rates (y=sqrt(2), y=x, y=x^2, y=asin(bx+c)+d)
     * -Optosensor and color sensor classes and methods
     *
     *
     *
     */







    //Main variables
    float x,y;
    bool testMode = true;

    //If test mode is enabled, use the touch condition instead of the light condition
    if (testMode)
    {
        goto TouchCondition;
    }
    goto LightCondition;



TouchCondition:

    //Start Condition: Wait for a touch of the screen
    screen.clearScreen();
    screen.displayFullScreenMessage("TAP TO START");

    LCD.ClearBuffer();

    while(!LCD.Touch(&x,&y))
    {}
    while(LCD.Touch(&x,&y))
    {}

    screen.clearScreen();
    drive.resetEncoders();
    screen.displayBatteryVoltage();

    goto DriveLoop;



LightCondition:

    //Start Condition: Wait for the light to turn on
    screen.clearScreen();
    LCD.ClearBuffer();
    drive.resetEncoders();

    goto DriveLoop;







DriveLoop:
    /*
     *  MAIN ROBOT COMMANDS
     */

    //Example command
    //while(drive.driveByEncoders(14.0, TEST_MOTOR_SPEED));




    while(commands.followLineForDistance(25.0, TEST_MOTOR_SPEED)){}

    /*
    while(true)
    {
        screen.displayAllOptosensorDetection();
        screen.displayAllOptosensorReading();
        Sleep(100);
        screen.clearScreen();
    }
    */






    //If test mode is enabled, use the touch condition instead of the light condition
    if (testMode)
    {
        goto TouchCondition;
    }
    goto LightCondition;


    return 0;
}
