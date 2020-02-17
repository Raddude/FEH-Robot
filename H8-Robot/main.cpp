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

#define TEST_MOTOR_SPEED 40

using namespace std;







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

    //Singleton Instances
    ScreenController* screen = ScreenController::getInstance();
    MainDriveController* drive = MainDriveController::getInstance();
    FileManager* fileIO = FileManager::getInstance();
    CdSController* cdsCell = CdSController::getInstance();
    Optosensors* optosensors = Optosensors::getInstance();


TouchCondition:

    //Start Condition: Wait for a touch of the screen
    screen->clearScreen();
    screen->displayFullScreenMessage("TAP TO START");

    LCD.ClearBuffer();

    while(!LCD.Touch(&x,&y))
    {}
    while(LCD.Touch(&x,&y))
    {}

    screen->clearScreen();
    drive->resetEncoders();
    screen->displayBatteryVoltage();







    /*
     *  MAIN ROBOT COMMANDS
     */

    while(true)
    {

    }





    goto TouchCondition;


    return 0;
}
