#ifndef REVENANT_FWDECORATOR_H
#define REVENANT_FWDECORATOR_H

class fwDecorator
{
public:
    inline static bool* decorator_commands__g_DecorRegistrationsLocked;
    static void InitialisePatterns();
};

#endif //REVENANT_FWDECORATOR_H