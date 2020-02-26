#ifndef FILEMANAGER_H
#define FILEMANAGER_H


class FileManager
{
public:
    FileManager();

    void openFiles();
    void closeFiles();

    void writeToFile(char, double);
    void writeToFile(char, int);
};

extern FileManager fileManager;

#endif // FILEMANAGER_H
