/*  CdSController.cpp
 *  Author: Jake Marchewitz
 *  Creation Date: 2/14/20
 *
 *  Purpose: This file is meant to house all methods and behaviors linked to the CdS cell.
 *
 *  Superclasses: None.
 *  Subclasses: None.
 *  Used in: None.
 *  Uses: None.
 */

#include <FEHIO.h>
#include "CdSController.h"

CdSController* instance = new CdSController();

AnalogInputPin CdSCell(FEHIO::P2_0);







CdSController::CdSController()
{

}

/*  This method returns the singleton instance of CdSController.cpp
 */
CdSController* CdSController::getInstance()
{
    return instance;
}
