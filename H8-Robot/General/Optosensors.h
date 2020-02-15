#ifndef OPTOSENSORS_H
#define OPTOSENSORS_H


class Optosensors
{
public:
    Optosensors();
    static Optosensors* getInstance();
    double getLeftOptosensor();
    double getMiddleOptosensor();
    double getRightOptosensor();

private:
    static Optosensors *instance;
};

#endif // OPTOSENSORS_H
