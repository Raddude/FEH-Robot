/*  ScreenController.cpp
 *  Author: Jake Marchewitz
 *  Creation Date: 2/10/20
 *
 *  Purpose: This is a file meant to control outputs screen and unify all custom screen methods into one place.
 *
 *  Superclasses: None.
 *  Subclasses: None.
 *  Used in: main.cpp.
 */

#include <FEHLCD.h>
#include <FEHBattery.h>
#include <string.h>
#include "Drive/MainDriveController.h"
#include "General/Time.h"
#include "Mechanisms/CdSController.h"
#include "Mechanisms/Optosensors.h"
#include "ScreenController.h"

#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 320

float x,y;

using namespace std;

ScreenController screen;






ScreenController::ScreenController()
{

}







/*  This method fills the screen with black and resets the font color and orientation.
 */
void ScreenController::clearScreen()
{
    LCD.Clear(FEHLCD::Black);
    LCD.SetFontColor(FEHLCD::White);
    LCD.SetOrientation(FEHLCD::East);
}

/*  This is a wrapper method for LCD.ClearBuffer()
 */
void ScreenController::clearBuffer()
{
    LCD.ClearBuffer();
}

/*  This method suspends the proteus until the screen is touched
 */
void ScreenController::waitForTouch()
{
    //while(LCD.Touch(&x,&y))
    {}
    while(!LCD.Touch(&x,&y))
    {}
}





/*  This method displays a screen on startup that allows the user to select test mode or performance mode
 */
bool ScreenController::testModeSelect()
{
    clearScreen();
    clearBuffer();

    LCD.WriteAt("TEST", SCREEN_WIDTH/2  - (6*strlen("TEST")), SCREEN_HEIGHT/4);
    LCD.WriteAt("PERFORM", SCREEN_WIDTH/2  - (6*strlen("PERFORM")), (3*SCREEN_HEIGHT)/4);
    LCD.FillRectangle(0, (SCREEN_HEIGHT/2)+3, SCREEN_WIDTH, 6);

    waitForTouch();

    if (x > SCREEN_HEIGHT/2)
    {
        return true;
    }

    else
    {
        return false;
    }
}





/*  This method writes a message to the center of the screen for clarity.
 *
 *  const char* input - The message to be displayed on screen.
 */
void ScreenController::displayFullScreenMessage(const char* input)
{
    //Try to make font size bigger if possible
    clearScreen();
    LCD.WriteAt(input, SCREEN_WIDTH/2  - (6*strlen(input)), SCREEN_HEIGHT/2);
}





/*  This function simply displays the battery's voltage in the top left corner.
 */
void ScreenController::displayBatteryVoltage()
{
    LCD.WriteLine(Battery.Voltage());
}





/*  This function displays the current value of the CdS cell to the screen.
 */
void ScreenController::displayCdSReading()
{
    LCD.WriteLine(cdsCell.getCurrentValue());
}

/*  This function displays the current detection of the CdS cell to the screen.
 */
void ScreenController::displayCdSDetection()
{
    if (cdsCell.isRed())
    {
        LCD.WriteLine("RED");
    }

    else if (cdsCell.isBlue())
    {
        LCD.WriteLine("BLUE");
    }

    else
    {
        LCD.WriteLine("NONE");
    }
}





/*  This function displays the reading of the selected optosensor.
 *
 *  char input - This letter (L, M, or R) represents which optosensor to display.
 */
void ScreenController::displayOptosensorReading(char input)
{
    if (input == 'L')
    {
        LCD.WriteLine('L');
        LCD.WriteLine(optosensors.getLeftOptosensor());
    }

    else if (input == 'M')
    {
        LCD.WriteLine('M');
        LCD.WriteLine(optosensors.getMiddleOptosensor());
    }

    else if (input == 'R')
    {
        LCD.WriteLine('R');
        LCD.WriteLine(optosensors.getRightOptosensor());
    }
}

/*  This function displays the reading of the selected optosensor.
 *
 *  char input - This letter (L, M, or R) represents which optosensor to display.
 */
void ScreenController::displayOptosensorDetection(char input)
{
    if (input == 'L')
    {
        LCD.WriteLine('L');
        LCD.WriteLine(optosensors.isLeftSeeingALine());
    }

    else if (input == 'M')
    {
        LCD.WriteLine('M');
        LCD.WriteLine(optosensors.isMiddleSeeingALine());
    }

    else if (input == 'R')
    {
        LCD.WriteLine('R');
        LCD.WriteLine(optosensors.isRightSeeingALine());
    }
}





/*  This method displays all 3 optosensor readings to the screen
 */
void ScreenController::displayAllOptosensorReading()
{
    displayOptosensorReading('L');
    displayOptosensorReading('M');
    displayOptosensorReading('R');
}

/*  This method displays all 3 optosensor detections to the screen
 */
void ScreenController::displayAllOptosensorDetection()
{
    displayOptosensorDetection('L');
    displayOptosensorDetection('M');
    displayOptosensorDetection('R');
}





/*  This method displays the tick count of a specific encoder
 *
 *  char input - The letter (L/R) corresponding to the left or right encoder to be displayed
 */
void ScreenController::displayEncoderCount(char input)
{
    if (input == 'L')
    {
        LCD.WriteLine("L");
        LCD.WriteLine(drive.getLeftEncoderCount());
    }

    else if (input == 'R')
    {
        LCD.WriteLine("R");
        LCD.WriteLine(drive.getRightEncoderCount());
    }
}

/*  This method displays the distance reading of a specific encoder
 *
 *  char input - The letter (L/R) corresponding to the left or right encoder to be displayed
 */
void ScreenController::displayEncoderDistance(char input)
{
    if (input == 'L')
    {
        LCD.WriteLine("L");
        LCD.WriteLine(drive.getLeftEncoderDistance());
    }

    else if (input == 'R')
    {
        LCD.WriteLine("R");
        LCD.WriteLine(drive.getRightEncoderDistance());
    }
}





/*  This method displays both encoder tick counts
 */
void ScreenController::displayAllEncoderCounts()
{
    displayEncoderCount('L');
    displayEncoderCount('R');
}

/*  This method displays both encoder distances
 */
void ScreenController::displayAllEncoderDistances()
{
    displayEncoderDistance('L');
    displayEncoderDistance('R');
}





/*  This method displays the current time
 */
void ScreenController::displayCurrentTime()
{
    LCD.Write("Time: ");
    LCD.Write(time.getCurrentTime());
}
