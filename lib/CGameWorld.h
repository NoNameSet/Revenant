#ifndef REVENANT_CGAMEWORLD_H
#define REVENANT_CGAMEWORLD_H

#include "CPed.h"

class CGameWorld
{
public:
    static CPed* FindPlayer();

    static void InitialisePatterns();
};

#endif //REVENANT_CGAMEWORLD_H