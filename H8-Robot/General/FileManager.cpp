/*  FileManager.cpp
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
#include "FileManager.h"

using namespace std;

FileManager fileManager;

int variables[0];







FileManager::FileManager()
{

}







/*  This method reads all of the tracked variables from the Stored_Values.txt.
 */
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

/*  This method writes all of the tracked variables to Stored_Variables.txt.
 */
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





/*  This method reads a specific variable from the array and returns it.
 *
 *  int ID - The index of the array being read. This can act as the variable's ID.
 */
int FileManager::readIntVariable(int ID)
{
    return variables[ID];
}

/*  This method writes a given value to a specific variable in the array.
 *
 *  int ID - The index of the array being read. This can act as the variable's ID.
 *  int value - The value being written to the variable.
 */
void FileManager::writeIntVariable(int ID, int value)
{
    variables[ID] = value;
}
