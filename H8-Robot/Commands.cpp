/*  Commands.cpp
 *  Author: Jake Marchewitz
 *  Creation Date: 2/14/20
 *
 *  Purpose: This file is the 'second-in-command' class behind main.cpp. It holds many of the commands (methods) that can be put inside a while(COMMAND){} statement in the main loop in main.cpp.
 *
 *  Superclasses: None.
 *  Subclasses: None.
 *  Used in: main.cpp.
 */

#include <FEHUtility.h>
#include "Commands.h"
#include "Drive/MainDriveController.h"
#include "General/Optosensors.h"
#include "General/ScreenController.h"
#include "General/LimitSwitches.h"
#include "Mechanisms/BurgerFlipper.h"

//Distance in inches that the robot moves before checking the line again
#define LINE_FOLLOWING_STEP_SIZE 0.05

//These are constants that apply to the input speed for the line following command. Close and far refer to the sides of the robot that are closer or farther away from the current position of the line. (Far>Close) will always be true.
#define LF_LOW_CLOSE_TURN_CONSTANT 0.625
#define LF_LOW_FAR_TURN_CONSTANT 1.375
#define LF_MED_CLOSE_TURN_CONSTANT 0.5
#define LF_MED_FAR_TURN_CONSTANT 1.5
#define LF_HIGH_CLOSE_TURN_CONSTANT 0
#define LF_HIGH_FAR_TURN_CONSTANT 1.5

Commands commands;

char sideWhereLineWasLastSeen = 'M';







Commands::Commands()
{

}







/*  This command performs all necessary resets before the match begins
 */
void Commands::preMatchReset()
{
    screen.clearScreen();
    screen.clearBuffer();
    drive.resetEncoders();
    burger.setEndStops();
    burger.setPosition('U');
}





/*  This method follows a black line on the drive surface for a specific distance at a specific speed.
 *
 *  double distance - The minimum distance either encoder needs to travel to end the command
 *  int speed - The motor speed at which the line follow is executed
 */
bool Commands::followLineForDistance(double distance, int speed)
{
    //THIS RUNS WELL AT ANY INPUT SPEED


    //End the command if the robot drove far enough
    if (drive.getLeftEncoderDistance() >= distance || drive.getRightEncoderDistance() >= distance)
    {
        drive.resetEncoders();
        drive.stopMotors();
        return false;
    }



    //High correction if no line is seen
    if (!optosensors.isLeftSeeingALine() && !optosensors.isMiddleSeeingALine() && !optosensors.isRightSeeingALine())
    {
        if (sideWhereLineWasLastSeen == 'L')
        {
            drive.driveByPower(speed*LF_HIGH_CLOSE_TURN_CONSTANT, speed*LF_HIGH_FAR_TURN_CONSTANT);
        }

        else if (sideWhereLineWasLastSeen == 'R' || sideWhereLineWasLastSeen == 'M')
        {
            drive.driveByPower(speed*LF_HIGH_FAR_TURN_CONSTANT, speed*LF_HIGH_CLOSE_TURN_CONSTANT);
        }

    }



    //Low correction if a line is seen on two sides
    else if (optosensors.isLeftSeeingALine() && optosensors.isMiddleSeeingALine())
    {
        drive.driveByPower(speed*LF_LOW_CLOSE_TURN_CONSTANT, speed*LF_LOW_FAR_TURN_CONSTANT);
        sideWhereLineWasLastSeen = 'L';
    }

    //Low correction if a line is seen on two sides
    else if (optosensors.isMiddleSeeingALine() && optosensors.isRightSeeingALine())
    {
        drive.driveByPower(speed*LF_LOW_FAR_TURN_CONSTANT, speed*LF_LOW_CLOSE_TURN_CONSTANT);
        sideWhereLineWasLastSeen = 'R';
    }



    //Medium correction if a line is only seen on one side
    else if (optosensors.isLeftSeeingALine())
    {
        drive.driveByPower(speed*LF_MED_CLOSE_TURN_CONSTANT, speed*LF_MED_FAR_TURN_CONSTANT);
        sideWhereLineWasLastSeen = 'L';
    }

    //Medium correction if a line is only seen on one side
    else if (optosensors.isRightSeeingALine())
    {
        drive.driveByPower(speed*LF_MED_FAR_TURN_CONSTANT, speed*LF_MED_CLOSE_TURN_CONSTANT);
        sideWhereLineWasLastSeen = 'R';
    }



    //No correction if a line is only seen in the middle
    else if (optosensors.isMiddleSeeingALine())
    {
        drive.driveByPower(speed, speed);
    }



    return true;
}





/*  This method drives in a given direction until given sensor(s) are depressed
 *
 *  char sensor - The character corresponding to a specific combination of limit switches to be depressed
 *  int speed - The speed at which the robot drives
 */
bool Commands::driveUntilLimitSwitch(char sensor, int speed)
{
    switch(sensor)
    {
        case 'B':
            if (limitSwitches.isBackLimitSwitchPressed())
            {
                return false;
            }
            break;
    }

    drive.driveByPower(speed, speed);
    return true;
}





/*  This command is meant to be run alone, and displays the value of all limit switches
 */
bool Commands::configureLimitSwitches()
{


    return true;
}





/*  This command is meant to be run alone, and displays the value and detection of each optosensor for configuration
 */
bool Commands::configureOptosensors()
{
    screen.displayAllOptosensorDetection();
    screen.displayAllOptosensorReading();
    Sleep(100);
    screen.clearScreen();

    return true;
}





/*  This command is meant to be run alone, and displays the value and detection of the CdS cell for configuration
 */
bool Commands::configureCdSCell()
{
    screen.displayCdSReading();
    screen.displayCdSDetection();
    Sleep(100);
    screen.clearScreen();

    return true;
}





/*  This command constantly updates the screen with the battery voltage
 */
bool Commands::showBatteryVoltage()
{
    screen.displayBatteryVoltage();
    Sleep(100);
    screen.clearScreen();

    return true;
}
