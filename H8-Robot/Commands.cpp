/*  Commands.cpp
 *  Author: Jake Marchewitz
 *  Creation Date: 2/14/20
 *
 *  Purpose: This file is the 'second-in-command' class behind main.cpp. It holds all of the commands that can be put inside a while(COMMAND){} statement in the main loop in main.cpp.
 *
 *  Superclasses: None.
 *  Subclasses: None.
 *  Used in: None.
 *  Uses: None.
 */

#include "Commands.h"
#include "Drive/MainDriveController.h"
#include "General/Optosensors.h"

#define LINE_FOLLOWING_STEP_SIZE 0.05 //Distance in inches that the robot moves before checking the line again
#define LINE_FOLLOWING_TURN_FACTOR 2 //Base of the fraction that the other side moves during a turn for line following

Commands commands;







Commands::Commands()
{

}







/*  This method follows a black line on the drive surface for a specific distance at a specific speed.
 *
 *  double distance - The minimum distance either encoder needs to travel to end the command
 *  int speed - The motor speed at which the line follow is executed
 */
bool Commands::followLineForDistance(double distance, int speed)
{
    //End the command if the robot drove far enough
    if (drive.getLeftEncoderDistance() >= distance || drive.getRightEncoderDistance() >= distance)
    {
        drive.resetEncoders();
        drive.stopMotors();
        return false;
    }



    if (optosensors.isMiddleSeeingALine())
    {
        drive.driveByPower(speed, speed);
    }

    else if (optosensors.isLeftSeeingALine())
    {
        drive.driveByPower(speed/LINE_FOLLOWING_TURN_FACTOR, speed*LINE_FOLLOWING_TURN_FACTOR);
    }

    else if (optosensors.isRightSeeingALine())
    {
        drive.driveByPower(speed*LINE_FOLLOWING_TURN_FACTOR, speed/LINE_FOLLOWING_TURN_FACTOR);
    }

    return true;
}

