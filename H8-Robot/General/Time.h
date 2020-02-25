#ifndef TIME_H
#define TIME_H


class Time
{
public:
    Time();

    void sleepSeconds(double);
    void sleepMS(int);
    void sleepStandard();

    void keepTime();
    double getCurrentTime();
    void resetTime();
};

extern Time time;

#endif // TIME_H
