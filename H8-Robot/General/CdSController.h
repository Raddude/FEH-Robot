#ifndef CDSCONTROLLER_H
#define CDSCONTROLLER_H


class CdSController
{
public:
    CdSController();
    static CdSController* getInstance();

private:
    static CdSController *instance;
};

#endif // CDSCONTROLLER_H
