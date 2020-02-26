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
#include "Drive/MainDriveController.h"
#include "Drive/DriveConstants.h"
#include "General/FileManager.h"
#include "General/ScreenController.h"
#include "General/Speed.h"
#include "General/Time.h"
#include "Mechanisms/BurgerFlipper.h"
#include "Mechanisms/CdSController.h"
#include "Mechanisms/IceCreamClaw.h"
#include "Mechanisms/Optosensors.h"
#include "Mechanisms/TicketSlider.h"
#include "Commands.h"

#define STRAIGHT_SPEED 40 //40 is the default value
#define TURN_SPEED 40

using namespace std;







int main(void)
{
    /*  TO-DO LIST
     *
     * -Speed functions relating to time, that take in time and output speeds at different rates (y=sqrt(2), y=x, y=x^2, y=asin(bx+c)+d)
     * -PID man
     * -Make the file manager work
     * -Turn about radius methods
     */







    //TEST MODE
    bool testMode = true;



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
    //while(drive.driveByEncoders(14.0, TEST_MOTOR_SPEED)){time.keepTime();}






    //






    screen.displayCurrentTime();
    Sleep(5.0);

    goto TouchCondition;







PerformanceLoop:



    /*  TICKET SLIDER  */
    while(drive.turnRight(60, TURN_SPEED)){time.keepTime();}
    while(drive.driveByEncoders(12.0, STRAIGHT_SPEED)){time.keepTime();}
    while(drive.turnLeft(195, TURN_SPEED)){time.keepTime();}
    while(drive.driveByEncoders(3.5, -STRAIGHT_SPEED)){time.keepTime();}
    while(commands.pivotUntilBackLimitSwitch('L', -TURN_SPEED)){time.keepTime();}
    //Slider arm down here
    while(drive.driveByEncoders(4.0, STRAIGHT_SPEED)){time.keepTime();}



    /*  TRAY RETURN  */
    while(drive.driveByEncoders(4.0, -STRAIGHT_SPEED)){time.keepTime();}
    //Slider arm up here
    while(drive.pivotLeft(45, TURN_SPEED)){time.keepTime();}
    while(drive.driveByEncoders(6.0, STRAIGHT_SPEED)){time.keepTime();}
    while(drive.turnRight(90, TURN_SPEED)){time.keepTime();}
    while(drive.driveByEncoders(10.0, STRAIGHT_SPEED)){time.keepTime();}
    while(drive.turnRight(90, TURN_SPEED)){time.keepTime();}
    while(drive.driveByEncoders(20.0, STRAIGHT_SPEED)){time.keepTime();}
    while(drive.turnRight(90, TURN_SPEED)){time.keepTime();}
    while(commands.driveUntilLimitSwitch('B', -STRAIGHT_SPEED)){time.keepTime();}
    //Dump tray here






    //If test mode is enabled, use the touch condition instead of the light condition
    screen.displayCurrentTime();
    time.sleepSeconds(5.0);
    screen.clearScreen();
    screen.displayFullScreenMessage("Touch to continue...");

    LCD.ClearBuffer();

    while(!LCD.Touch(&x,&y))
    {}
    while(LCD.Touch(&x,&y))
    {}

    goto LightCondition;


    return 0;
}
