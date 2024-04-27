#ifndef REVENANT_PLAYERCONTROLLER_H
#define REVENANT_PLAYERCONTROLLER_H

#pragma once

#include "Script.h"
#include "../GTA/entities/Model.h"

namespace revenant
{
    enum PLAYER_STATE_TYPE
    {
        PST_Normal,
        PST_Survivor
    };

    class PlayerController : public Script
    {
    public:
        explicit PlayerController() = default;
        ~PlayerController() noexcept override = default;

        bool IsInitialized() override;
        void Initialize() override;
        void Destroy() override;
        void Tick() override;
        void SetPlayerState(PLAYER_STATE_TYPE stateType);

    public:
        PLAYER_STATE_TYPE m_PlayerState = PST_Normal;
    private:
        bool m_Initialized {};
        Model m_DefaultModel = ENTITY::GET_ENTITY_MODEL(PLAYER::PLAYER_PED_ID());
    };

    inline std::shared_ptr<PlayerController> g_PlayerController;
}

#endif //REVENANT_PLAYERCONTROLLER_H