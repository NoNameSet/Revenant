#include "PickupController.h"
#include "PlayerController.h"
#include "../GTA.UI/Screen.h"
#include "../GTA/entities/Player.h"

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
            if (prop.IsValid())
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

            for (auto&& prop : m_Pickups)
            {
                if (prop.IsValid())
                {
                    float distance = prop.GetPosition().Distance(Player::GetCharacter()->GetPosition());
                }
            }

            if (m_Pickups.size() < MAX_PICKUP_COUNT && (currentTime - m_LastPickupCreatedAt) >= 5000)
            {
                m_LastPickupCreatedAt = currentTime;
            }
        }
    }
}