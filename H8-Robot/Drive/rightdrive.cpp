/*  RightDrive.cpp
 *  Author: Jake Marchewitz
 *  Creation Date: 2/10/20
 *
 *  Purpose: This is a sub-class of DriveBase and contains any right-half specific methods.
 *
 *  Superclasses: DriveBase.cpp.
 *  Subclasses: None.
 *  Used in: MainDriveController.cpp.
 *  Uses: None.
 */

#include "rightdrive.h"







RightDrive::RightDrive()
{

}







//Corrected right half drive
void RightDrive::driveRightCorrected(int speed)
{
    driveRightMotor(speed);
}
