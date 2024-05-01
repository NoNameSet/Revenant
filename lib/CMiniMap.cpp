#include "CMiniMap.h"

rage::fvector2* (*CMiniMap__GetCurrentMiniMapPosition) (rage::fvector2*);
rage::fvector2* (*CMiniMap__GetCurrentMiniMapSize) (rage::fvector2*);

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

rage::fvector2 *CMiniMap::GetCurrentMiniMapPosition(rage::fvector2 *position)
{
    return CMiniMap__GetCurrentMiniMapPosition(position);
}

rage::fvector2 *CMiniMap::GetCurrentMiniMapSize(rage::fvector2 *size)
{
    return CMiniMap__GetCurrentMiniMapSize(size);
}