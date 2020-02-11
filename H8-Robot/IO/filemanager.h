#ifndef FILEMANAGER_H
#define FILEMANAGER_H


class FileManager
{
public:
    FileManager();
    void readAllFromFile();
    void writeAllToFile();
    int readIntVariable(int);
    void writeIntVariable(int);
};

#endif // FILEMANAGER_H
