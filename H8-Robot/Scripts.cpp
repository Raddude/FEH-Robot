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

}
