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
#include "General/RPSManager.h"
#include "General/Sound.h"
#include "Mechanisms/BurgerFlipper.h"
#include "Mechanisms/CdSController.h"
#include "Mechanisms/IceCreamClaw.h"
#include "Mechanisms/Optosensors.h"
#include "Mechanisms/TicketSlider.h"
#include "Commands.h"
#include "Scripts.h"

using namespace std;







int main(void)
{
    /*  TO-DO LIST
     *
     * -Actually implement PID
     * -Test orbit functions
     * -Convert FileManager to be a state manager
     * -Motor voltage compensation (break) (TJ said it is barely useful)
     * -Error detection (list in notebook)
     * -Check if set distances are true for the current run
     * -Know when to give up on a task
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
     *  iceCream.setPosition('CHAR'); - (L)ow, (M)iddle, (H)igh, (U)p  - THIS IS UNTESTED
     */









    //TEST MODE
    bool testMode = true;

    rps.initializeTouchMenu();


SelectionScreen:

    //If test mode is enabled, use the touch condition instead of the light condition

    commands.preMatchReset();

    if (screen.testModeSelect())
    {
        testMode = true;
        goto TouchCondition;
    }
    testMode = false;
    goto LightCondition;



TouchCondition:

    //Start Condition: Wait for a touch of the screen
    screen.displayFullScreenMessage("TAP TO START");

    LCD.ClearBuffer();
    screen.waitForTouch();

    commands.preMatchReset();
    goto TestLoop;



LightCondition:

    //Start Condition: Wait for the light to turn on
    screen.displayFullScreenMessage("Waiting...");

    while(!cdsCell.isRed()){}

    commands.preMatchReset();
    goto PerformanceLoop;







TestLoop:


    //screen.displayBatteryVoltage();
    //time.sleepSeconds(5.0);


    scripts.performanceTest3and4();


    screen.clearScreen();
    //screen.displayCurrentTime();



    //Post-match
    commands.postMatchActions();
    goto SelectionScreen;







PerformanceLoop:





    scripts.bottomLevel();
    scripts.topLevel();





    //Post-match
    commands.postMatchActions();
    goto SelectionScreen;


    return 0;
}
