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

int variables[100][2], numRows;







FileManager::FileManager()
{

}







//Read and write the entire variables[][] array to and from the Stored_Values.txt file
void FileManager::readAllFromFile()
{
    FEHFile *fptr = SD.FOpen("Stored_Values.txt", "r");
    int i = 0;

    while(!SD.FEof(fptr))
    {
        variables[i][0] = i;
        SD.FScanf(fptr, "%d", &variables[i][1]);
        i++;
    }

    SD.FClose(fptr);
}

void FileManager::writeAllToFile()
{
    remove("Stored_Values.txt");

    FEHFile *fptr = SD.FOpen("Stored_Values.txt", "w");

    numRows = sizeof(variables)/sizeof(variables[0]);

    for(int j = 0; j < numRows; j++)
    {
        SD.FPrintf(fptr, "%i", variables[j][2]);
    }

    SD.FClose(fptr);
}



//Read and write specific variables from the array read from the SD
int FileManager::readIntVariable(int ID)
{

}

void FileManager::writeIntVariable(int ID)
{

}
