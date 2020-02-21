/*  CdSController.cpp
 *  Author: Jake Marchewitz
 *  Creation Date: 2/14/20
 *
 *  Purpose: This file is meant to house all methods and behaviors linked to the CdS cell.
 *
 *  Superclasses: None.
 *  Subclasses: None.
 *  Used in: Commands.cpp, ScreenController.cpp.
 */

#include <FEHIO.h>
#include "CdSController.h"

#define RED_MIN_THRESHOLD 0.031
#define RED_MAX_THRESHOLD 0.49
#define BLUE_MIN_THRESHOLD 0.5
#define BLUE_MAX_THRESHOLD 1

CdSController cdsCell;

AnalogInputPin CdSCell(FEHIO::P2_0);







CdSController::CdSController()
{

}







/*  This method returns whether or not the CdS cell is currently reading red.
 */
bool CdSController::isRed()
{
    if(CdSCell.Value() > RED_MIN_THRESHOLD && CdSCell.Value() < RED_MAX_THRESHOLD)
    {
        return true;
    }

    return false;
}

/*  This method returns whether or not the CdS cell is currently reading red.
 */
bool CdSController::isBlue()
{
    if(CdSCell.Value() > BLUE_MIN_THRESHOLD && CdSCell.Value() < BLUE_MAX_THRESHOLD)
    {
        return true;
    }

    return false;
}





/*  This method returns the current value of the CdS cell
 */
double CdSController::getCurrentValue()
{
    return CdSCell.Value();
}
