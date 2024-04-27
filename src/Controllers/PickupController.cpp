#include "PickupController.h"
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
        for (auto&& prop : m_Pickups)
        {
            prop.Delete();
        }
    }

    void PickupController::Tick()
    {
        if (g_PlayerController->m_PlayerState == PST_Normal)
            return;

        int currentTime = MISC::GET_GAME_TIMER();

        if (m_LastUpdateAt < currentTime)
        {
            m_LastUpdateAt = currentTime + 1000;

            if (m_Pickups.size() < MAX_PICKUP_COUNT && (currentTime - m_LastPickupCreatedAt) >= 5000)
            {
                m_LastPickupCreatedAt = currentTime;

                
            }
        }
    }
}