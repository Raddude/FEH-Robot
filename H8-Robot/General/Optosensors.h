#ifndef OPTOSENSORS_H
#define OPTOSENSORS_H


class Optosensors
{
public:
    Optosensors();
    Optosensors* getInstance();
    double getLeftOptosensor();
    double getMiddleOptosensor();
    double getRightOptosensor();
};

#endif // OPTOSENSORS_H
