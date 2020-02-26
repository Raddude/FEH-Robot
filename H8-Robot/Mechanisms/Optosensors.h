#ifndef OPTOSENSORS_H
#define OPTOSENSORS_H


class Optosensors
{
public:
    Optosensors();

    double getLeftOptosensor();
    double getMiddleOptosensor();
    double getRightOptosensor();
    bool isLeftSeeingALine();
    bool isMiddleSeeingALine();
    bool isRightSeeingALine();
};

extern Optosensors optosensors;

#endif // OPTOSENSORS_H
