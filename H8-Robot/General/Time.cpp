/*  Time.cpp
 *  Author: Jake Marchewitz
 *  Creation Date: 2/14/20
 *
 *  Purpose: This file stores central timing methods, as well as a total time of the current run. This file works in conjunction with the speed inputs of certain functions of MainDriveController.cpp to provide for gradual speed-ups and downs.
 *
 *  Superclasses: None.
 *  Subclasses: None.
 *  Used in: main.cpp.
 */

#include <FEHUtility.h>
#include <General/FileManager.h>
#include "Time.h"

#define TIME_INCREMENT 0.001 //Time to sleep in seconds
#define STANDARD_TIME_DELAY 500 //MS

Time time;

double globalTime = 0; //Time in seconds
double stopwatchTime = 0;







Time::Time()
{

}







/*  This method sleeps the code for an amount of time
 *
 *  double time - Time in SECONDS to wait
 */
void Time::sleepSeconds(double time)
{
    Sleep(time);
    globalTime += time;
}

/*  This method sleeps the code for an amount of time
 *
 *  int time - Time in MILLISECONDS to wait
 */
void Time::sleepMS(int time)
{
    Sleep(time);
    globalTime += time/1000;
}

/*  This method sleeps a standard time after any command
 */
void Time::sleepStandard()
{
    sleepMS(STANDARD_TIME_DELAY);
}





/*  This method returns the current time of the stopwatch
 */
double Time::getStopwatch()
{
    return stopwatchTime;
}

/*  This method resets the stopwatch time back to 0
 */
void Time::resetStopwatch()
{
    stopwatchTime = 0;
}





/*  This method keeps the time for the code and increments the global timer by the TIME_INCREMENT constant
 */
void Time::keepTime()
{
    Sleep(TIME_INCREMENT);
    globalTime += TIME_INCREMENT;
    stopwatchTime += TIME_INCREMENT;

    fileManager.writeStateToFile();
}

/*  This method returns the current global time
 */
double Time::getCurrentTime()
{
    return globalTime;
}

/*  This method resets the current time to 0
 */
void Time::resetTime()
{
    globalTime = 0;
}
