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
     * -PID man
     * -Test orbit functions
     * -Test file functions
     */



    /*  EXAMPLE COMMANDS - FOR MOUSTAPHA AND CLAY
     *  You can basically copy and paste each of these lines into the code and edit the parameters as needed
     *
     *  All distances are in INCHES, all angles are in DEGREES, and all speeds are a PERCENT
     *  Speeds STRAIGHT_SPEED and TURN_SPEED, have been tested and are the most accurate speeds to run the program at.
     *  They are constants made with #define at the top
     *
     *  while(drive.driveByEncoders(DISTANCE, SPEED){time.keepTime();} - FORWARDS
     *  while(drive.driveByEncoders(DISTANCE, -SPEED){time.keepTime();} - BACKWARDS (Note that the distance is still positive)
     *
     *  while(drive.turnLeft(ANGLE, SPEED)){time.keepTime();}
     *  while(drive.turnRight(ANGLE, SPEED)){time.keepTime();}
     *
     *  while(drive.pivotLeft(ANGLE, SPEED)){time.keepTime();}
     *  while(drive.pivotRight(ANGLE, SPEED)){time.keepTime();}
     *
     *  while(commands.pivotUntilBackLimitSwitch('L', -TURN_SPEED)){time.keepTime();} - PIVOT LEFT UNTIL BACK LIMIT SWITCH
     *  while(commands.pivotUntilBackLimitSwitch('R', -TURN_SPEED)){time.keepTime();} - PIVOT RIGHT UNTIL BACK LIMIT SWITCH
     *
     *  NOT INSIDE WHILE() LOOPS:
     *  burger.setPosition('CHAR'); - (L)eft, (U)p, or (R)ight
     *  ticketSlider.setPosition('CHAR'); - (U)p, (M)iddle, or (D)own  - THIS IS SEMI-UNTESTED
     *  iceCream.setPosition('CHAR'); - (L)ow, (Middle), (H)igh, (U)p  - THIS IS UNTESTED
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
    goto TestLoop;



LightCondition:

    //Start Condition: Wait for the light to turn on
    screen.displayFullScreenMessage("Waiting...");

    while(!cdsCell.isRed()){}

    commands.preMatchReset();
    goto PerformanceLoop;







TestLoop:
    //Example command
    //while(drive.driveByEncoders(14.0, TEST_MOTOR_SPEED)){time.keepTime();}





    while(drive.driveByEncoders(12.0, speed.rampSpeed(12.0, 80))){time.keepTime();}





    //Post-match
    commands.postMatchActions();
    goto TouchCondition;







PerformanceLoop:



    /*  TICKET SLIDER  */
    while(drive.turnRight(60, TURN_SPEED)){time.keepTime();}
    while(drive.driveByEncoders(12.0, STRAIGHT_SPEED)){time.keepTime();}
    while(drive.turnLeft(195, TURN_SPEED)){time.keepTime();}
    while(drive.driveByEncoders(3.5, -STRAIGHT_SPEED)){time.keepTime();}
    while(commands.pivotUntilBackLimitSwitch('L', -TURN_SPEED)){time.keepTime();}
    //Untested - ticketSlider.setPosition('D');
    while(drive.driveByEncoders(4.0, STRAIGHT_SPEED)){time.keepTime();}



    /*  TRAY RETURN  */
    while(drive.driveByEncoders(4.0, -STRAIGHT_SPEED)){time.keepTime();}
    //Untested - ticketSlider.setPosition('U');
    while(drive.pivotLeft(45, TURN_SPEED)){time.keepTime();}
    while(drive.driveByEncoders(7.0, STRAIGHT_SPEED)){time.keepTime();}
    while(drive.turnRight(45, TURN_SPEED)){time.keepTime();}
    while(drive.driveByEncoders(9.0, STRAIGHT_SPEED)){time.keepTime();}
    while(drive.turnRight(90, TURN_SPEED)){time.keepTime();}
    while(drive.driveByEncoders(20.0, STRAIGHT_SPEED)){time.keepTime();}
    while(drive.turnRight(90, TURN_SPEED)){time.keepTime();}
    while(commands.driveUntilLimitSwitch('B', -STRAIGHT_SPEED)){time.keepTime();}
    //Dump tray here



    /*  BURGER TOUCH */
    while(drive.pivotLeft(60, TURN_SPEED)){time.keepTime();}
    while(drive.driveByEncoders(25.0, STRAIGHT_SPEED)){time.keepTime();}
    while(drive.turnLeft(30, TURN_SPEED)){time.keepTime();}
    while(drive.driveByEncoders(4.0, STRAIGHT_SPEED)){time.keepTime();}





    //Post-match
    commands.postMatchActions();
    goto LightCondition;


    return 0;
}
