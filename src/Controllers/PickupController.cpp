#include "PickupController.h"

#pragma once

#include "PlayerController.h"

namespace revenant
{
    bool PickupController::IsInitialized()
    {
        return m_Initialized;
    }

    void PickupController::Initialize()
    {
        m_Initialized = true;
    }

    void PickupController::Destroy()
    {
    }

    void PickupController::Tick()
    {
        if (g_PlayerController->m_PlayerState == PST_Normal)
            return;


    }
}