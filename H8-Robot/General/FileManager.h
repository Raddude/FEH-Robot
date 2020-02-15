#ifndef FILEMANAGER_H
#define FILEMANAGER_H


class FileManager
{
public:
    FileManager();
    static FileManager* getInstance();
    void readAllVariables();
    void writeAllVariables();
    int readIntVariable(int);
    void writeIntVariable(int, int);

private:
    static FileManager *instance;
};

#endif // FILEMANAGER_H
