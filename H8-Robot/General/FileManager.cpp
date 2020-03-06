/*  FileManager.cpp
 *  Author: Jake Marchewitz
 *  Creation Date: 2/11/20
 *
 *  Purpose: This is a file meant to control reading and writing files on the Proteus' SD card.
 *
 *  Superclasses: None.
 *  Subclasses: None.
 *  Used in: main.cpp.
 */

#include <FEHSD.h>
#include <FEHUtility.h>
#include <stdio.h>
#include "Time.h"
#include "FileManager.h"
#include "Drive/MainDriveController.h"
#include "Mechanisms/BurgerFlipper.h"
#include "Mechanisms/CdSController.h"
#include "Mechanisms/IceCreamClaw.h"
#include "Mechanisms/LimitSwitches.h"
#include "Mechanisms/Optosensors.h"
#include "Mechanisms/TicketSlider.h"

using namespace std;

FileManager fileManager;

//FEHFile *robotState = SD.FOpen("StateLog.txt", "w");







FileManager::FileManager()
{

}







/*  This method opens and clears the state file
 */
void FileManager::openFile()
{

}

/*  This method closes the state file
 */
void FileManager::closeFile()
{
    SD.FCloseAll();
}





/*  This method puts titles above each column in the state file
 */
void FileManager::writeHeaderToFile()
{
    //SD.FPrintf(robotState, "%s", "Time");
}

/*  This method takes in data from all sensors on the robot and plots them to a large, timestamped state file for debugging
 */
void FileManager::writeStateToFile()
{
    //SD.FPrintf(robotState, "%f", time.getCurrentTime());
}
