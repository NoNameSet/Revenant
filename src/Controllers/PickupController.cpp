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
            {
                prop.SetAsMissionEntity();
                prop.Delete();
            }
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

            for (int i = 0; i < m_Pickups.size(); i++)
            {
                auto prop = m_Pickups[i];

                if (prop.IsValid())
                {
                    float distance = prop.GetPosition().Distance(Player::GetCharacter()->GetPosition());

                    if (distance >= PICKUP_DISPOSE_DISTANCE)
                    {
                        m_Pickups.erase(m_Pickups.begin() + i);
                        prop.SetAsMissionEntity();
                        prop.Delete();
                    }
                }
            }

            if (m_Pickups.size() < MAX_PICKUP_COUNT && (currentTime - m_LastPickupCreatedAt) >= 5000)
            {
                m_LastPickupCreatedAt = currentTime;

                g_Logger->Info("Created prop!");

                Vector3 position = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false).Around(5.0f);
                Prop prop = Prop("v_ret_gc_ammo3", position);
                prop.SetAsMissionEntity();
                prop.PlaceOnGroundProperly();
                m_Pickups.push_back(prop);
            }
        }
    }
}