#ifndef TIME_H
#define TIME_H


class Time
{
public:
    Time();
    static Time* getInstance();

private:
    static Time *instance;
};

#endif // TIME_H
