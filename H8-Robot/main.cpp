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

#include "IO/screencontroller.h"
#include "IO/filemanager.h"
#include "Drive/maindrivecontroller.h"

#define DRIVE_MOTOR_SPEED 35

using namespace std;







int main(void)
{
    //Main variables
    float x,y;
    int timer = 0;

    //Singleton Instances
    ScreenController* screen = new ScreenController();
    MainDriveController* drive = new MainDriveController();
    FileManager* fileIO = new FileManager();



    //Start Condition: Wait for a touch of the screen
    screen->clearScreen();
    screen->displayFullScreenMessage("TAP TO START");

    while(!LCD.Touch(&x,&y))
    {}
    while(LCD.Touch(&x,&y))
    {}

    screen->clearScreen();





    //Drive straight for a while
    drive->driveByEncoders(4.0, 40);

    //OR

    while(true)
    {
        drive->driveByEncoders(4, 40);
    }




    return 0;
}
