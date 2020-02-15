#ifndef ICECREAMCLAW_H
#define ICECREAMCLAW_H


class IceCreamClaw
{
public:
    IceCreamClaw();
    static IceCreamClaw* getInstance();

private:
    static IceCreamClaw *instance;
};

#endif // ICECREAMCLAW_H
