#ifndef FILEMANAGER_H
#define FILEMANAGER_H


class FileManager
{
public:
    FileManager();
    void readAllVariables();
    void writeAllVariables();
    int readIntVariable(int);
    void writeIntVariable(int, int);
};

#endif // FILEMANAGER_H
