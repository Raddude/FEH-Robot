/*  RPSManager.cpp
 *  Author: Jake Marchewitz
 *  Creation Date: 3/2/20
 *
 *  Purpose: This is a file meant to house all RPS data.
 *
 *  Superclasses: None.
 *  Subclasses: None.
 *  Used in: main.cpp.
 */

#include <FEHRPS.h>
#include "RPSManager.h"

using namespace std;

RPSManager rps;







RPSManager::RPSManager()
{

}







/*  This is a wrapper for InitializeTouchMenu()
 */
void RPSManager::initializeTouchMenu()
{
    RPS.InitializeTouchMenu();
}

/*  This is a wrapper for InitializeMenu()
 */
void RPSManager::initializeMenu()
{
   RPS.InitializeMenu();
}



/*  This is a wrapper for X()
 */
double RPSManager::getX()
{
    return RPS.X();
}

/*  This is a wrapper for Y()
 */
double RPSManager::getY()
{
    return RPS.Y();
}

/*  This is a wrapper for Heading()
 */
double RPSManager::getHeading()
{
    return RPS.Heading();
}



/*  This is a wrapper for Time()
 */
int RPSManager::timeRemaining()
{
    return RPS.Time();
}

/*  This is a wrapper for CurrentCourse()
 */
char RPSManager::currentCourse()
{
    return RPS.CurrentCourse();
}

/*  This is a wrapper for CurrentRegionLetter
 */
char RPSManager::currentRegionLetter()
{
    return RPS.CurrentRegionLetter();
}

/*  This is a wrapper for CurrentRegion
 */
int RPSManager::currentRegion()
{
    return RPS.CurrentRegion();
}

/*  This is a wrapper for GetIceCream()
 */
char RPSManager::getIceCream()
{
    if (RPS.GetIceCream() == 0)
    {
        return 'L';
    }

    else if (RPS.GetIceCream() == 1)
    {
        return 'M';
    }

    else if (RPS.GetIceCream() == 2)
    {
        return 'R';
    }
}
