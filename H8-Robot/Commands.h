#ifndef COMMANDS_H
#define COMMANDS_H


class Commands
{
public:
    Commands();
    static Commands* getInstance();

private:
    static Commands *instance;
};

#endif // COMMANDS_H
