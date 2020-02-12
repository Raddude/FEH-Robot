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
#include <stdio.h>
#include "filemanager.h"

int variables[100];







FileManager::FileManager()
{

}







//Read and write the entire variables[][] array to and from the Stored_Values.txt file
void FileManager::readAllVariables()
{
    FEHFile *fptr = SD.FOpen("Stored_Values.txt", "r");
    int i = 0;

    while(!SD.FEof(fptr))
    {
        SD.FScanf(fptr, "%d", &variables[i]);
        i++;
    }

    SD.FClose(fptr);
}

void FileManager::writeAllVariables()
{
    remove("Stored_Values.txt");

    FEHFile *fptr = SD.FOpen("Stored_Values.txt", "w");

    for(int j = 0; j < 100; j++)
    {
        SD.FPrintf(fptr, "%i\n", variables[j]);
    }

    SD.FClose(fptr);
}



//Read and write specific variables from the array read from the SD
int FileManager::readIntVariable(int ID)
{
    return variables[ID];
}

void FileManager::writeIntVariable(int ID, int value)
{
    variables[ID] = value;
}
