/*  Time.cpp
 *  Author: Jake Marchewitz
 *  Creation Date: 2/14/20
 *
 *  Purpose: This file stores central timing methods, as well as a total time of the current run. This file works in conjunction with the speed inputs of certain functions of MainDriveController.cpp to provide for gradual speed-ups and downs.
 *
 *  Superclasses: None.
 *  Subclasses: None.
 *  Used in: main.cpp.
 *  Uses: None.
 */

#include "Time.h"

Time* Time::instance = 0;







Time::Time()
{

}

/*  This method returns the singleton instance of Time.cpp
 */
Time* Time::getInstance()
{
    if (instance == 0)
    {
        instance = new Time();
    }
    return instance;
}