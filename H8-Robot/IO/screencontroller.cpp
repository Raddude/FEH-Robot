/*  ScreenController.cpp
 *  Author: Jake Marchewitz
 *  Creation Date: 2/10/20
 *
 *  Purpose: This is a file meant to control outputs screen and unify all custom screen methods into one place.
 *
 *  Superclasses: None.
 *  Subclasses: None.
 *  Used in: main.cpp.
 *  Uses: None.
 */

#include <FEHLCD.h>
#include <FEHBattery.h>
#include <string>
#include "screencontroller.h"

#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 320

using namespace std;







ScreenController::ScreenController()
{

}







void ScreenController::clearScreen()
{
    LCD.Clear(FEHLCD::Black);
    LCD.SetFontColor(FEHLCD::White);
    LCD.SetOrientation(FEHLCD::North);
}



void ScreenController::displayFullScreenMessage(const char* input)
{
    //Write at the center of the screen, LARGE
    LCD.WriteAt(input, SCREEN_HEIGHT/2  - (6*strlen(input)), SCREEN_WIDTH/2);
}



void ScreenController::displayBatteryVoltage()
{
    LCD.WriteLine(Battery.Voltage());
}
