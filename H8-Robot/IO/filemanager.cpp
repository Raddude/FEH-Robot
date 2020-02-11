/*  ScreenController.cpp
 *  Author: Jake Marchewitz
 *  Creation Date: 2/11/20
 *
 *  Purpose: This is a file meant to control reading and writing files on the Proteus' SD card.
 *
 *  Superclasses: None.
 *  Subclasses: None.
 *  Used in: main.cpp.
 *  Uses: None.
 */

#include <FEHSD.h>
#include "filemanager.h"

FileManager::FileManager()
{
    FEHFile *fptr = SD.FOpen("Variables.txt", "r+");

    SD.FClose(fptr);
}
