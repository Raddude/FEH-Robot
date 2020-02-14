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
#include "ScreenController.h"

#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 320

using namespace std;

ScreenController* instance = new ScreenController();







ScreenController::ScreenController()
{

}

/*  This method returns the singleton instance of ScreenController.cpp
 */
ScreenController* ScreenController::getInstance()
{
    return instance;
}





/*  This method fills the screen with black and resets the font color and orientation.
 */
void ScreenController::clearScreen()
{
    LCD.Clear(FEHLCD::Black);
    LCD.SetFontColor(FEHLCD::White);
    LCD.SetOrientation(FEHLCD::North);
}





/*  This method writes a message to the center of the screen for clarity.
 *
 *  const char* input - The message to be displayed on screen.
 */
void ScreenController::displayFullScreenMessage(const char* input)
{
    //Try to make font size bigger if possible
    clearScreen();
    LCD.WriteAt(input, SCREEN_HEIGHT/2  - (6*strlen(input)), SCREEN_WIDTH/2);
}





/*  This function simply displays the battery's voltage in the top left corner.
 */
void ScreenController::displayBatteryVoltage()
{
    LCD.WriteLine(Battery.Voltage());
}
