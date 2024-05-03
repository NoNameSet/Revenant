#include <GTA.UI/Screen.h>
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
        m_PlayerState = PST_Survivor;
        m_DefaultModel = ENTITY::GET_ENTITY_MODEL(PLAYER::PLAYER_PED_ID());

        g_Logger->Info("[PlayerController] PlayerController has been initialized.");
    }

    void PlayerController::Destroy()
    {
        m_PlayerState = PST_Normal;
        PLAYER::SET_PLAYER_MODEL(PLAYER::PLAYER_ID(), m_DefaultModel.GetModelHash());

        g_Logger->Info("[PlayerController] PlayerController has been cleaned up.");
    }

    void PlayerController::Tick()
    {
    }

    void PlayerController::SetPlayerState(PLAYER_STATE_TYPE stateType)
    {
        if (m_PlayerState == stateType)
            return;

        g_Logger->Info("Changing player state from %s to %s",
                       m_PlayerState == PST_Survivor ? "PST_Survivor" : "PST_Normal",
                       stateType == PST_Normal ? "PST_Normal" : "PST_Survivor");

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