#include "PlayerController.h"

namespace revenant
{
    bool PlayerController::IsInitialized()
    {
        return m_Initialized;
    }

    void PlayerController::Initialize()
    {
        m_Initialized = true;
        m_PlayerState = PST_Normal;
        m_DefaultModel = ENTITY::GET_ENTITY_MODEL(PLAYER::PLAYER_PED_ID());
    }

    void PlayerController::Destroy()
    {
        m_PlayerState = PST_Normal;

        PLAYER::SET_PLAYER_MODEL(PLAYER::PLAYER_ID(), m_DefaultModel.GetModelHash());
    }

    void PlayerController::Tick()
    {
        if (m_PlayerState == PST_Normal)
            return;

        
    }

    void PlayerController::SetPlayerState(PLAYER_STATE_TYPE stateType)
    {
        if (m_PlayerState == stateType)
            return;

        switch (stateType)
        {
            case PST_Normal:
                PLAYER::SET_PLAYER_MODEL(PLAYER::PLAYER_ID(), m_DefaultModel.GetModelHash());
                break;
            case PST_Survivor:
                break;
        }

        m_PlayerState = stateType;
    }
}