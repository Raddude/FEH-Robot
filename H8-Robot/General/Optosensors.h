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
    bool isLeftSeeingALine();
    bool isMiddleSeeingALine();
    bool isRightSeeingALine();

private:
    static Optosensors *instance;
};

#endif // OPTOSENSORS_H
