/*  Commands.cpp
 *  Author: Jake Marchewitz
 *  Creation Date: 2/14/20
 *
 *  Purpose: This file is the 'second-in-command' class behind main.cpp. It holds all of the commands that can be put inside a while(COMMAND){} statement in the main loop in main.cpp.
 *
 *  Superclasses: None.
 *  Subclasses: None.
 *  Used in: None.
 *  Uses: None.
 */

#include "Commands.h"

Commands* Commands::instance = 0;







Commands::Commands()
{

}

/*  This method returns the singleton instance of Commands.cpp
 */
Commands* Commands::getInstance()
{
    if (instance == 0)
    {
        instance = new Commands();
    }
    return instance;
}
