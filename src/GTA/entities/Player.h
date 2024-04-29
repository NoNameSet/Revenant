#ifndef REVENANT_PLAYER_H
#define REVENANT_PLAYER_H

#pragma once

#include "../entities/peds/Ped.h"
#include "Model.h"
#include "../entities/peds/PedGroup.h"

namespace revenant
{
    class Player
    {
    public:
        static void SetModel(const Model& model);
        static void SetWantedLevel(int level);
        static void SetMaxWantedLevel(int level);
        static void SetControl(bool setControlOn, SET_PLAYER_CONTROL_FLAGS flags);

        static int GetWantedLevel();
        static int GetMaxWantedLevel();
        static int GetId();

        static bool IsPlaying();
        static bool IsFreeAiming();
        static bool IsFreeAimingAtEntity(const Entity& entity);
        static bool IsControlOn();

        static std::unique_ptr<PedGroup> GetGroup();
        static std::unique_ptr<Entity> GetFreeAimingTarget();
        static std::unique_ptr<Ped> GetCharacter();
    };
}

#endif //REVENANT_PLAYER_H