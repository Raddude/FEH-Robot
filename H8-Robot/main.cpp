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
#include "Commands.h"

#define TEST_MOTOR_SPEED 40 //40 is the default value

using namespace std;







int main(void)
{
    /*  TO-DO LIST
     *
     * -Timer class, that constantly counts up and manages time
     * -Speed functions relating to time, that take in time and output speeds at different rates (y=sqrt(2), y=x, y=x^2, y=asin(bx+c)+d)
     *
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

    screen.clearScreen();
    drive.resetEncoders();

    if (testMode)
    {
        goto TestLoop;
    }
    goto PerformanceLoop;



LightCondition:

    //Start Condition: Wait for the light to turn on
    screen.clearScreen();
    LCD.ClearBuffer();
    drive.resetEncoders();

    while(!cdsCell.isRed()){}

    if (testMode)
    {
        goto TestLoop;
    }
    goto PerformanceLoop;







TestLoop:
    //Example command
    //while(drive.driveByEncoders(14.0, TEST_MOTOR_SPEED));





    //





    //If test mode is enabled, use the touch condition instead of the light condition
    if (testMode)
    {
        goto TouchCondition;
    }
    goto LightCondition;







PerformanceLoop:

    //Tray
    while(drive.turnLeft(10.0, TEST_MOTOR_SPEED)){}
    while(drive.driveByEncoders(20.0, TEST_MOTOR_SPEED)){}
    while(commands.followLineForDistance(15.0, TEST_MOTOR_SPEED)){}



    //Button
    while(drive.driveByEncoders(2.0, -TEST_MOTOR_SPEED)){}
    while(drive.turnRight(160.0, TEST_MOTOR_SPEED)){}
    while(drive.driveByEncoders(2.0, -TEST_MOTOR_SPEED)){}
    while(drive.turnRight(45.0, TEST_MOTOR_SPEED)){}
    while(drive.driveByEncoders(6.0, -TEST_MOTOR_SPEED)){}
    while(drive.turnLeft(30.0, TEST_MOTOR_SPEED)){}
    while(commands.followLineForDistance(7.375, TEST_MOTOR_SPEED)){}
    while(drive.turnLeft(15.0, TEST_MOTOR_SPEED)){}
    while(drive.driveByEncoders(3.0, TEST_MOTOR_SPEED)){}
    while(drive.turnRight(20.0, TEST_MOTOR_SPEED)){}

    //Button Selection
    if (cdsCell.isBlue()) //BLUE
    {
        while(drive.turnLeft(20.0, TEST_MOTOR_SPEED)){}
        while(drive.driveByEncoders(2.0, TEST_MOTOR_SPEED)){}
        while(commands.followLineForDistance(7.5, TEST_MOTOR_SPEED)){}
        //Button Push Here
        while(drive.driveByEncoders(4.0, -TEST_MOTOR_SPEED)){}
        while(drive.turnLeft(135.0, TEST_MOTOR_SPEED)){}
        while(drive.driveByEncoders(8.0, TEST_MOTOR_SPEED)){}
    }

    else if (cdsCell.isRed()) //RED
    {
        while(drive.turnRight(20.0, TEST_MOTOR_SPEED)){}
        while(drive.driveByEncoders(2.0, TEST_MOTOR_SPEED)){}
        while(commands.followLineForDistance(7.5, TEST_MOTOR_SPEED)){}
        //Button Push Here
        while(drive.driveByEncoders(4.0, -TEST_MOTOR_SPEED)){}
        while(drive.turnLeft(135.0, TEST_MOTOR_SPEED)){}
        while(drive.driveByEncoders(10.0, TEST_MOTOR_SPEED)){}
    }

    else
    {
        goto TouchCondition;
    }



    //Ramp
    while(drive.turnLeft(70.0, TEST_MOTOR_SPEED)){}
    while(drive.turnLeft(180.0, TEST_MOTOR_SPEED)){}
    while(drive.driveByEncoders(24.0, -TEST_MOTOR_SPEED/2)){}




    //If test mode is enabled, use the touch condition instead of the light condition
    if (testMode)
    {
        goto TouchCondition;
    }
    goto LightCondition;


    return 0;
}
