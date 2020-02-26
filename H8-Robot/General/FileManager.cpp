/*  FileManager.cpp
 *  Author: Jake Marchewitz
 *  Creation Date: 2/11/20
 *
 *  Purpose: This is a file meant to control reading and writing files on the Proteus' SD card.
 *
 *  Superclasses: None.
 *  Subclasses: None.
 *  Used in: main.cpp.
 */

#include <FEHSD.h>
#include <FEHUtility.h>
#include <stdio.h>
#include "Time.h"
#include "FileManager.h"

using namespace std;

FileManager fileManager;

FEHFile *fileA;
FEHFile *fileB;
FEHFile *fileC;







FileManager::FileManager()
{

}







/*  This method opens all of the documented files
 */
void FileManager::openFiles()
{
    //*fileA = SD.FOpen("File_A.txt", 'w');
    //*fileB = SD.FOpen("File_B.txt", 'w');
    //*fileC = SD.FOpen("File_C.txt", 'w');
}

/*  This method closes all of the documented files
 */
void FileManager::closeFiles()
{
    SD.FCloseAll();
}





/*  This method writes the given data to the selected file, with the robot's global time attached
 *
 *  char file - The file to be written to
 *  double data - The current data point to be written
 */
void FileManager::writeToFile(char file, double data)
{
    if (file == 'A')
    {
        SD.FPrintf(fileA, "%f\t%f", time.getCurrentTime(), data);
    }

    else if (file == 'B')
    {
        SD.FPrintf(fileB, "%f\t%f", time.getCurrentTime(), data);
    }

    else if (file == 'C')
    {
        SD.FPrintf(fileC, "%f\t%f", time.getCurrentTime(), data);
    }
}

/*  This method writes the given data to the selected file, with the robot's global time attached
 *
 *  char file - The file to be written to
 *  int data - The current data point to be written
 */
void FileManager::writeToFile(char file, int data)
{
    if (file == 'A')
    {
        SD.FPrintf(fileA, "%f\t%d", time.getCurrentTime(), data);
    }

    else if (file == 'B')
    {
        SD.FPrintf(fileB, "%f\t%d", time.getCurrentTime(), data);
    }

    else if (file == 'C')
    {
        SD.FPrintf(fileC, "%f\t%d", time.getCurrentTime(), data);
    }
}
