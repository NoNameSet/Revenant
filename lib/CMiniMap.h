#ifndef REVENANT_CMINIMAP_H
#define REVENANT_CMINIMAP_H

#pragma once

#include "vector.h"

class CMiniMap
{
public:
    static rage::fvector2* GetCurrentMiniMapPosition(rage::fvector2* position);
    static rage::fvector2* GetCurrentMiniMapSize(rage::fvector2* size);

    static void InitialisePatterns();
};

#endif //REVENANT_CMINIMAP_H