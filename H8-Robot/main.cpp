/*  MAIN.CPP
 *  Author: Jake Marchewitz
 *  Creation Date: 2/10/20
 *
 *  Purpose: This file is the hub for the robot's control system, and is the highest level class in the project. The main method is called regularly and often, and acts as an overview of the entire robot's function.
 *
 *  Superclasses: None.
 *  Subclasses: None.
 *  Used in: None.
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
#include "Drive/LeftDrive.h"
#include "Mechanisms/BurgerFlipper.h"
#include "Commands.h"

#define TEST_MOTOR_SPEED 40 //40 is the default value

using namespace std;







int main(void)
{
    /*  TO-DO LIST
     *
     * -Timer class, that constantly counts up and manages time
     * -Speed functions relating to time, that take in time and output speeds at different rates (y=sqrt(2), y=x, y=x^2, y=asin(bx+c)+d)
     * -PID man
     * -PT1
     */







    //TEST MODE
    bool testMode = false;



    //Other variables
    float x,y;

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

    commands.preMatchReset();


    if (testMode)
    {
        goto TestLoop;
    }
    goto PerformanceLoop;



LightCondition:

    //Start Condition: Wait for the light to turn on
    screen.displayFullScreenMessage("Waiting...");

    while(!cdsCell.isRed()){}

    commands.preMatchReset();

    if (testMode)
    {
        goto TestLoop;
    }
    goto PerformanceLoop;







TestLoop:
    //Example command
    //while(drive.driveByEncoders(14.0, TEST_MOTOR_SPEED));





    while(commands.configureCdSCell()){}





    //If test mode is enabled, use the touch condition instead of the light condition
    if (testMode)
    {
        goto TouchCondition;
    }
    goto LightCondition;







PerformanceLoop:




    //Jukebox
    while(drive.driveByEncoders(20.0, TEST_MOTOR_SPEED)){}
    while(drive.turnLeft(45, TEST_MOTOR_SPEED)){}
    while(drive.driveByEncoders(3.5, TEST_MOTOR_SPEED)){}
    while(drive.turnLeft(90, TEST_MOTOR_SPEED)){}
    while(drive.driveByEncoders(3.25, TEST_MOTOR_SPEED)){}
    screen.displayCdSDetection();
    Sleep(3.0);

    if(cdsCell.isRed())
    {
        burger.setPosition('R');
    }

    else if (cdsCell.isBlue())
    {
        burger.setPosition('L');
    }

    else
    {
        burger.setPosition('U');
    }

    /*
    while(drive.driveByEncoders(6.5, TEST_MOTOR_SPEED)){}
    while(drive.driveByEncoders(6.5, -TEST_MOTOR_SPEED)){}
    */




    //If test mode is enabled, use the touch condition instead of the light condition


    goto LightCondition;


    return 0;
}
