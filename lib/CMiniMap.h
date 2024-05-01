#ifndef REVENANT_CMINIMAP_H
#define REVENANT_CMINIMAP_H

#pragma once

class CMiniMap
{
public:
    static Vector2* GetCurrentMiniMapPosition(Vector2* position);
    static Vector2* GetCurrentMiniMapSize(Vector2* size);

    static void InitialisePatterns();
};

#endif //REVENANT_CMINIMAP_H