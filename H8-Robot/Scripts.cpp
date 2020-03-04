/*  Scripts.cpp
 *  Author: Jake Marchewitz
 *  Creation Date: 3/4/20
 *
 *  Purpose: This file is the high level action class behind main.cpp. It hold many different groups of actions to be called in main.cpp.
 *
 *  Superclasses: None.
 *  Subclasses: None.
 *  Used in: main.cpp.
 */

#include <FEHUtility.h>
#include <FEHLCD.h>
#include "Drive/DriveConstants.h"
#include "Drive/MainDriveController.h"
#include "General/FileManager.h"
#include "General/ScreenController.h"
#include "General/Time.h"
#include "General/RPSManager.h"
#include "Mechanisms/BurgerFlipper.h"
#include "Mechanisms/CdSController.h"
#include "Mechanisms/IceCreamClaw.h"
#include "Mechanisms/LimitSwitches.h"
#include "Mechanisms/Optosensors.h"
#include "Mechanisms/TicketSlider.h"
#include "Commands.h"
#include "Scripts.h"

Scripts scripts;







Scripts::Scripts()
{

}







/*  This performs any necessary resets before the execution of a new script
 */
void Scripts::preScriptReset()
{
    time.resetStopwatch();
}





/*  This script completes PT1
 */
void Scripts::performanceTest1()
{
    while(drive.driveByEncoders(20.0, driveConstants.straightSpeed())){}
    while(drive.turnLeft(45, driveConstants.turnSpeed())){}
    while(drive.driveByEncoders(3.5, driveConstants.straightSpeed())){}
    while(drive.turnLeft(90, driveConstants.turnSpeed())){}
    while(commands.driveUntilLightDetected(5.0, driveConstants.straightSpeed())){}
    while(drive.driveByEncoders(0.2, driveConstants.straightSpeed())){}
    Sleep(1.0);

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
    Sleep(2.0);
    while(drive.driveByEncoders(4.5, driveConstants.straightSpeed())){}



    //Ramp
    while(drive.driveByEncoders(6.5, -driveConstants.straightSpeed())){}
    while(drive.turnLeft(110, driveConstants.turnSpeed())){}
    while(drive.driveByEncoders(10.0, driveConstants.straightSpeed())){}
    while(drive.turnLeft(70, driveConstants.turnSpeed())){}
    while(drive.driveByEncoders(25.0, driveConstants.straightSpeed())){}
    while(drive.driveByEncoders(35.0, -driveConstants.straightSpeed())){}
}

/*  This script completes PT2
 */
void Scripts::performanceTest2()
{
    /*  TICKET SLIDER  */
    while(drive.driveByEncoders(1, driveConstants.straightSpeed())){time.keepTime();}
    while(drive.turnRight(70, driveConstants.turnSpeed())){time.keepTime();}
    while(drive.driveByEncoders(12.5, driveConstants.straightSpeed())){time.keepTime();}
    while(drive.turnLeft(193.5, driveConstants.turnSpeed())){time.keepTime();}
    while(commands.driveUntilLimitSwitch('B', -driveConstants.straightSpeed())){time.keepTime();}
    while(drive.driveByEncoders(7.25, driveConstants.straightSpeed())){time.keepTime();}
    ticketSlider.setPosition('M');
    while(drive.pivotLeft(90, -driveConstants.turnSpeed())){time.keepTime();}
    while(commands.driveUntilLimitSwitch('B', -driveConstants.straightSpeed())){time.keepTime();}
    ticketSlider.setPosition('D');
    while(drive.driveByEncoders(5.45, driveConstants.straightSpeed(), 5, driveConstants.straightSpeed()+15 )){time.keepTime();}



    /*  TRAY RETURN  */
    while(drive.driveByEncoders(4.5, -driveConstants.straightSpeed())){time.keepTime();}
    ticketSlider.setPosition('M');
    while(drive.pivotLeft(85, driveConstants.turnSpeed())){time.keepTime();}
    ticketSlider.setPosition('U');
    while(drive.driveByEncoders(7, driveConstants.straightSpeed())){time.keepTime();}
    while(drive.pivotRight(82, -driveConstants.turnSpeed())){time.keepTime();}
    while(commands.driveUntilLimitSwitch('B', -driveConstants.straightSpeed())){time.keepTime();}
    while(drive.driveByEncoders(1.31, driveConstants.straightSpeed())){time.keepTime();}
    while(drive.pivotRight(85, driveConstants.turnSpeed())){time.keepTime();}
    while(commands.driveUntilLimitSwitch('B', -driveConstants.straightSpeed())){time.keepTime();}
    iceCream.setPosition('M');
    time.sleepSeconds(0.5);
    while(drive.driveByEncoders(10, driveConstants.straightSpeed())){time.keepTime();}



    /*  BURGER TOUCH  */
    iceCream.setPosition('U');
    while(drive.pivotRight(82, -driveConstants.turnSpeed())){time.keepTime();}
    while(commands.driveUntilLimitSwitch('B', -driveConstants.straightSpeed())){time.keepTime();}
    while(drive.driveByEncoders(10, driveConstants.straightSpeed())){time.keepTime();}
    while(drive.turnRight(90, driveConstants.turnSpeed())){time.keepTime();}
    while(drive.driveByEncoders(20, driveConstants.straightSpeed() + 10)){time.keepTime();}
    while(drive.pivotRight(85, driveConstants.turnSpeed())){time.keepTime();}
    while(drive.driveByEncoders(5, driveConstants.straightSpeed())){time.keepTime();}
    while(drive.pivotLeft(85, driveConstants.turnSpeed())){time.keepTime();}
    while(drive.driveByEncoders(15, driveConstants.straightSpeed())){time.keepTime();}
}

/*  This script completes PT3
 */
void Scripts::performanceTest3()
{
    //Drive up ramp to burger
    while(drive.driveByEncoders(12, driveConstants.straightSpeed())){time.keepTime();}
    while(drive.turnRight(45, driveConstants.turnSpeed())){time.keepTime();}
    while(drive.driveByEncoders(30, driveConstants.straightSpeed())){time.keepTime();}
    while(drive.turnLeft(90, driveConstants.turnSpeed())){time.keepTime();}
    while(commands.driveUntilLightDetected('B', -driveConstants.straightSpeed())){time.keepTime();}
    while(drive.driveByEncoders(10, driveConstants.straightSpeed())){time.keepTime();}
    burger.setPosition('L');
    while(drive.turnRight(90, driveConstants.turnSpeed())){time.keepTime();}
    while(drive.driveByEncoders(10, driveConstants.straightSpeed())){time.keepTime();}
    burger.setPosition('U');
    time.sleepSeconds(1.5);

    //Drive to ice cream
    burger.setPosition('L');
    while(drive.driveByEncoders(5, -driveConstants.straightSpeed())){time.keepTime();}
    while(drive.turnLeft(90, driveConstants.turnSpeed())){time.keepTime();}
    while(drive.driveByEncoders(12, driveConstants.straightSpeed())){time.keepTime();}
    iceCream.setPosition('H');
    while(drive.turnLeft(45, driveConstants.turnSpeed())){time.keepTime();}

    if (rps.getIceCream() == 'L')
    {
        while(drive.driveByEncoders(3, driveConstants.straightSpeed())){time.keepTime();}
    }

    else if (rps.getIceCream() == 'M')
    {
        while(drive.driveByEncoders(5, driveConstants.straightSpeed())){time.keepTime();}
    }

    else if (rps.getIceCream() == 'R')
    {
        while(drive.driveByEncoders(8, driveConstants.straightSpeed())){time.keepTime();}
    }

    while(drive.turnRight(90, driveConstants.turnSpeed())){time.keepTime();}
    while(drive.driveByEncoders(4.0, driveConstants.straightSpeed())){time.keepTime();}
    iceCream.setPosition('L');
    time.sleepSeconds(7.25);
    iceCream.setPosition('H');
    while(drive.driveByEncoders(4.0, -driveConstants.straightSpeed())){time.keepTime();}
}

/*  This script completes PT4
 */
void Scripts::performanceTest4()
{

}
