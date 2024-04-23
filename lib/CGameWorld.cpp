#pragma once

#include "CGameWorld.h"
#include "Utils.h"

CPed* (*CGameWorld__FindPlayer) (uint8_t playerId);

void CGameWorld::InitialisePatterns()
{
    ConvertCall(
            hook::get_pattern(
                    "48 83 EC 28 84 C9 75 0D 48 8B 05 ? ? ? ? 48 8B 40 08 EB 21"),
                        CGameWorld__FindPlayer);
}

CPed* CGameWorld::FindPlayer()
{
    return CGameWorld__FindPlayer(PLAYER::PLAYER_ID());
}