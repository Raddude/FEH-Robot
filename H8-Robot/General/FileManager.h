#ifndef FILEMANAGER_H
#define FILEMANAGER_H


class FileManager
{
public:
    FileManager();

    void openFile();
    void closeFile();

    void writeStateToFile();
    void writeHeaderToFile();
};

extern FileManager fileManager;

#endif // FILEMANAGER_H
