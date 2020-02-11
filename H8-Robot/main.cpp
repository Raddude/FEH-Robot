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

#include "Screen/screencontroller.h"
#include "Drive/maindrivecontroller.h"

#define DRIVE_MOTOR_SPEED 35





int main(void)
{
    //Main variables
    float x,y;
    int timer = 0;

    //Singleton Instances
    ScreenController* screen = new ScreenController();
    MainDriveController* drive = new MainDriveController();



    //Start Condition: Wait for a touch of the screen
    screen->clearScreen();
    screen->displayFullScreenMessage("TAP TO START");

    while(!LCD.Touch(&x,&y))
    {}
    while(LCD.Touch(&x,&y))
    {}

    screen->clearScreen();



    //Drive straight for a while
    drive->driveMotors(DRIVE_MOTOR_SPEED, DRIVE_MOTOR_SPEED);



    return 0;
}
