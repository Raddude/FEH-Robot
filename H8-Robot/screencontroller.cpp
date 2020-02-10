#include <FEHLCD.h>

#include "screencontroller.h"

#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 320





ScreenController::ScreenController()
{

}





ScreenController::clearScreen()
{
    LCD.Clear(FEHLCD::Black);
    LCD.SetFontColor(FEHLCD::White);
}

ScreenController::displayFullScreenMessage(String input)
{
    //Write at the center of the screen, LARGE
    //LCD.WriteAt(input, );
}
