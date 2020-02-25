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
#include "General/Time.h"
#include "Drive/MainDriveController.h"
#include "Drive/DriveConstants.h"
#include "Drive/LeftDrive.h"
#include "Mechanisms/BurgerFlipper.h"
#include "Mechanisms/IceCreamClaw.h"
#include "Commands.h"

#define STRAIGHT_SPEED 60 //40 is the default value
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












    screen.displayCurrentTime();
    Sleep(5.0);

    //If test mode is enabled, use the touch condition instead of the light condition
    if (testMode)
    {
        goto TouchCondition;
    }
    goto LightCondition;







PerformanceLoop:




    //Jukebox
    while(drive.driveByEncodersCorrected(20.0, TEST_MOTOR_SPEED)){time.keepTime();}
    while(drive.turnLeft(45, TURN_SPEED)){time.keepTime();}
    while(drive.driveByEncodersCorrected(3.5, TEST_MOTOR_SPEED)){time.keepTime();}
    while(drive.turnLeft(90, TEST_MOTOR_SPEED)){time.keepTime();}
    while(commands.driveUntilLightDetected(5.0, TEST_MOTOR_SPEED)){time.keepTime();}
    while(drive.driveByEncodersCorrected(0.2, TEST_MOTOR_SPEED)){time.keepTime();}
    time.sleepSeconds(1.0);

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

    screen.displayCdSDetection();
    time.sleepSeconds(2.0);


    //while(drive.turnLeft(5.0, TEST_MOTOR_SPEED)){}
    while(drive.driveByEncodersCorrected(4.5, TEST_MOTOR_SPEED)){time.keepTime();}



    //Ramp
    while(drive.driveByEncodersCorrected(6.5, -TEST_MOTOR_SPEED)){time.keepTime();}
    while(drive.turnLeft(110, TEST_MOTOR_SPEED)){time.keepTime();}
    while(drive.driveByEncodersCorrected(10.0, TEST_MOTOR_SPEED)){time.keepTime();}
    while(drive.turnLeft(70, TEST_MOTOR_SPEED)){time.keepTime();}
    while(drive.driveByEncodersCorrected(25.0, TEST_MOTOR_SPEED)){time.keepTime();}
    while(drive.driveByEncodersCorrected(35.0, -TEST_MOTOR_SPEED)){time.keepTime();}





    //If test mode is enabled, use the touch condition instead of the light condition
    screen.displayCurrentTime();
    time.sleepSeconds(5.0);
    goto TouchCondition;


    return 0;
}
