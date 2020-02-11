/*  LeftDrive.cpp
 *  Author: Jake Marchewitz
 *  Creation Date: 2/10/20
 *
 *  Purpose: This is a sub-class of DriveBase and contains any left-half specific methods.
 *
 *  Superclasses: DriveBase.cpp.
 *  Subclasses: None.
 *  Used in: MainDriveController.cpp.
 *  Uses: None.
 */

#include <FEHMotor.h>
#include "leftdrive.h"







LeftDrive::LeftDrive()
{

}







//Corrected left half drive function
void LeftDrive::driveLeftCorrected(int speed)
{
    driveLeftMotor(speed);
}
