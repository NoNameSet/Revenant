#include "CMiniMap.h"

Vector2* (*CMiniMap__GetCurrentMiniMapPosition) (Vector2*);
Vector2* (*CMiniMap__GetCurrentMiniMapSize) (Vector2*);

void CMiniMap::InitialisePatterns()
{
    auto match = hook::pattern ("E8 ? ? ? ? 48 8B 08 48 89 4D 88").get_one();

    ReadCall(
            match.get<void>(),
                    CMiniMap__GetCurrentMiniMapPosition);

    ReadCall(
            match.get<void>(19),
                    CMiniMap__GetCurrentMiniMapSize);
}

Vector2 *CMiniMap::GetCurrentMiniMapPosition(Vector2 *position)
{
    return CMiniMap__GetCurrentMiniMapPosition(position);
}

Vector2 *CMiniMap::GetCurrentMiniMapSize(Vector2 *size)
{
    return CMiniMap__GetCurrentMiniMapSize(size);
}