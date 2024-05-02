#include "PickupController.h"
#include "PlayerController.h"
#include "../GTA.UI/Screen.h"
#include "../GTA/entities/Player.h"
#include "fwDecorator.h"

namespace revenant
{
    bool PickupController::IsInitialized()
    {
        return m_Initialized;
    }

    void PickupController::Initialize()
    {
        m_Initialized = true;

        *fwDecorator::decorator_commands__g_DecorRegistrationsLocked = false;
        DECORATOR::DECOR_REGISTER("bWasNotifiedOfPickup", 2);
        *fwDecorator::decorator_commands__g_DecorRegistrationsLocked = true;
    }

    void PickupController::Destroy()
    {
        for (auto&& prop : m_Pickups)
        {
            if (prop.first.IsValid())
            {
                prop.first.SetAsMissionEntity();
                prop.first.Delete();
            }

            if (prop.second.Exists())
            {
                prop.second.Delete();
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

                if (prop.first.IsValid())
                {
                    float distance = prop.first.GetPosition().Distance(Player::GetCharacter()->GetPosition());

                    if (distance >= PICKUP_DISPOSE_DISTANCE)
                    {
                        m_Pickups.erase(m_Pickups.begin() + i);
                        prop.first.SetAsMissionEntity();
                        prop.first.Delete();

                        if (prop.second.Exists())
                            prop.second.Delete();
                    }
                    else
                    {
                        if (distance >= PICKUP_COLLECT_DISTANCE)
                        {
                            HUD::BEGIN_TEXT_COMMAND_IS_THIS_HELP_MESSAGE_BEING_DISPLAYED("STRING");
                            HUD::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("Press ~INPUT_CONTEXT~ to pick up the loot.");
                            bool shouldClear = HUD::END_TEXT_COMMAND_IS_THIS_HELP_MESSAGE_BEING_DISPLAYED(0);

                            if (shouldClear)
                                HUD::CLEAR_HELP(true);

                            if (DECORATOR::DECOR_GET_BOOL(prop.first.GetHandle(), "bWasNotifiedOfPickup"))
                                DECORATOR::DECOR_SET_BOOL(prop.first.GetHandle(), "bWasNotifiedOfPickup", false);
                        }
                        else
                        {
                            if (!DECORATOR::DECOR_EXIST_ON(prop.first.GetHandle(), "bWasNotifiedOfPickup") || !DECORATOR::DECOR_GET_BOOL(prop.first.GetHandle(), "bWasNotifiedOfPickup"))
                            {
                                DECORATOR::DECOR_SET_BOOL(prop.first.GetHandle(), "bWasNotifiedOfPickup", true);
                                Screen::DisplayHelp("Press ~INPUT_CONTEXT~ to pick up the loot.", false, true, 5000);
                            }
                        }
                    }
                }
            }

            if (m_Pickups.size() < MAX_PICKUP_COUNT && (currentTime - m_LastPickupCreatedAt) >= 5000)
            {
                m_LastPickupCreatedAt = currentTime;

                Vector3 position = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false).Around(5.0f);
                Prop prop = Prop("v_ret_gc_ammo3", position);
                prop.SetAsMissionEntity();
                prop.PlaceOnGroundProperly();

                Blip blip = Blip(prop);
                blip.SetSprite(RADAR_TRACE_FINDERS_KEEPERS);
                blip.SetScale(0.6f);
                blip.SetColor(RGBA(252, 186, 3, 255));
                blip.SetName("Pickup");
                blip.SetShortRange(true);

                m_Pickups.emplace_back(prop, blip);
            }
        }
    }
}