/*  Commands.cpp
 *  Author: Jake Marchewitz
 *  Creation Date: 2/14/20
 *
 *  Purpose: This file is the base level action class behind main.cpp. It holds many of the commands (methods) that can be put inside a while(COMMAND){} statement in the main loop in main.cpp.
 *
 *  Superclasses: None.
 *  Subclasses: None.
 *  Used in: main.cpp.
 */

#include <FEHUtility.h>
#include <FEHLCD.h>
#include "Commands.h"
#include "Drive/MainDriveController.h"
#include "General/FileManager.h"
#include "General/ScreenController.h"
#include "General/Time.h"
#include "Mechanisms/BurgerFlipper.h"
#include "Mechanisms/CdSController.h"
#include "Mechanisms/IceCreamClaw.h"
#include "Mechanisms/LimitSwitches.h"
#include "Mechanisms/Optosensors.h"
#include "Mechanisms/TicketSlider.h"

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
    //fileManager.writeHeaderToFile();
    screen.clearScreen();
    screen.clearBuffer();
    drive.resetEncoders();
    burger.setEndStops();
    burger.setPosition('U');
    iceCream.setEndStops();
    iceCream.setPosition('U');
    ticketSlider.setEndStops();
    ticketSlider.setPosition('U');
    time.resetTime();
}

/*  This command resets the robot after executing a command.
 */
void Commands::postMoveReset()
{
    drive.stopMotors();
    time.sleepStandard();
    drive.resetEncoders();
    time.resetStopwatch();
}

/*  This command performs a few key actions after a match
 */
void Commands::postMatchActions()
{
    fileManager.closeFile();

    drive.stopMotors();

    burger.setPosition('U');
    iceCream.setPosition('U');
    ticketSlider.setPosition('U');

    screen.displayCurrentTime();
    time.sleepSeconds(10.0);
    screen.clearScreen();
    screen.displayFullScreenMessage("Touch to continue...");

    LCD.ClearBuffer();

    screen.waitForTouch();
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
        postMoveReset();
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
                postMoveReset();
                return false;
            }
            break;
    }

    drive.driveByPower(speed, speed);
    return true;
}

/*  This method pivots the robot in a diven direction until the back limit switch is pressed
 */
bool Commands::pivotUntilBackLimitSwitch(char side, int speed)
{
    if (limitSwitches.isBackLimitSwitchPressed())
    {
        postMoveReset();
        return false;
    }

    if (side == 'L')
    {
        drive.driveByPower(0, speed);
    }

    else if (side == 'R')
    {
        drive.driveByPower(speed, 0);
    }

    return true;
}

/*  This method drives forward until it either sees a light or crosses the threshold distance
 *
 *  double distance - The maximum distance the robot is allowed to scan for a light
 *  int speed - The speed at which the robot drives forward
 */
bool Commands::driveUntilLightDetected(double distance, int speed)
{
    if (leftDrive.getLeftEncoderDistance() > distance || rightDrive.getRightEncoderDistance() > distance)
    {
        postMoveReset();
        return false;
    }

    else if (cdsCell.isBlue() || cdsCell.isRed())
    {
        return false;
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
    screen.clearScreen();

    return true;
}

/*  This command is meant to be run alone, and displays the value and detection of the CdS cell for configuration
 */
bool Commands::configureCdSCell()
{
    screen.displayCdSReading();
    screen.displayCdSDetection();
    screen.clearScreen();

    return true;
}

/*  This command constantly updates the screen with the battery voltage
 */
bool Commands::showBatteryVoltage()
{
    screen.displayBatteryVoltage();
    screen.clearScreen();

    return true;
}
