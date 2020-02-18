#ifndef COMMANDS_H
#define COMMANDS_H

#include "General/Optosensors.h"


class Commands
{
public:
    Commands();

    bool followLineForDistance(double, int);
};

extern Commands commands;

#endif // COMMANDS_H
