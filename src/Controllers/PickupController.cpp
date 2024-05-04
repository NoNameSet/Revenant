#include "PickupController.h"
#include "PlayerController.h"
#include "../GTA.UI/Screen.h"
#include "../GTA/Sound.h"
#include "../GTA/Control.h"
#include "../GTA/entities/Player.h"
#include "fwDecorator.h"
#include "color32.h"

namespace revenant
{
    bool PickupController::IsInitialized()
    {
        return m_Initialized;
    }

    void PickupController::Initialize()
    {
        m_Initialized = true;

        m_Choices.emplace_back("Ammunition", "v_ret_gc_ammo5", [](){  });

        *fwDecorator::decorator_commands__g_DecorRegistrationsLocked = false;
        DECORATOR::DECOR_REGISTER("bWasNotifiedOfPickup", 2);
        *fwDecorator::decorator_commands__g_DecorRegistrationsLocked = true;

        g_Logger->Info("[PickupController] PickupController has been initialized.");
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
                prop.second.Delete();
        }

        g_Logger->Info("[PickupController] PickupController has been cleaned up.");
    }

    void PickupController::Tick()
    {
        if (g_PlayerController->m_PlayerState == PST_Normal)
            return;

        int currentTime = MISC::GET_GAME_TIMER();

        for (int i = 0; i < m_Pickups.size(); i++)
        {
            auto prop = m_Pickups[i];

            if (prop.first.IsValid())
            {
                float distance = prop.first.GetPosition().Distance(Player::GetCharacter()->GetPosition());

                if (distance >= PICKUP_DISPOSE_DISTANCE)
                {
                    m_Pickups.erase(m_Pickups.begin() + i);

                    g_Logger->Info("[PickupController] Deleting pickup with handle %d", prop.first.GetHandle());

                    prop.first.SetAsMissionEntity();
                    prop.first.Delete();

                    if (prop.second.Exists())
                        prop.second.Delete();
                }
                else
                {
                    if (distance > PICKUP_COLLECT_DISTANCE)
                    {
                        HUD::BEGIN_TEXT_COMMAND_IS_THIS_HELP_MESSAGE_BEING_DISPLAYED("STRING");
                        HUD::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("Press ~INPUT_CONTEXT~ to pick up the loot.");
                        bool shouldClear = HUD::END_TEXT_COMMAND_IS_THIS_HELP_MESSAGE_BEING_DISPLAYED(0);

                        if (shouldClear)
                            HUD::CLEAR_HELP(true);
                    }
                    else
                    {
                        Screen::DisplayHelp("Press ~INPUT_CONTEXT~ to collect the item.", false, true, 10);

                        if (Control::IsJustPressed(PLAYER_CONTROL, INPUT_CONTEXT))
                        {
                            g_Logger->Info("[PickupController] Collected pickup with handle %d", prop.first.GetHandle());

                            if (prop.first.IsValid())
                            {
                                prop.first.SetAsMissionEntity();
                                prop.first.Delete();
                            }

                            if (prop.second.Exists())
                                prop.second.Delete();

                            m_Pickups.erase(m_Pickups.begin() + i);

                            if (!STREAMING::HAS_ANIM_DICT_LOADED("pickup_object"))
                                STREAMING::REQUEST_ANIM_DICT("pickup_object");

                            m_State = PickUp;
                        }
                    }
                }
            }
        }

        if (m_Pickups.size() < MAX_PICKUP_COUNT && (currentTime - m_LastPickupCreatedAt) >= 5000)
        {
            m_LastPickupCreatedAt = currentTime + 5000;

            Vector3 position = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false).Around(5.0f);
            Prop prop = Prop("v_ret_gc_ammo3", position);
            prop.SetAsMissionEntity();
            prop.PlaceOnGroundProperly();

            Blip blip = Blip(prop);
            blip.SetSprite(RADAR_TRACE_FINDERS_KEEPERS);
            blip.SetScale(0.6f);
            blip.SetColor(rage::Color32(252, 186, 3));
            blip.SetName("Pickup");
            blip.SetShortRange(true);

            m_Pickups.emplace_back(prop, blip);

            g_Logger->Info("[PickupController] Created new pickup with handle %d at (%f, %f, %f).", prop.GetHandle(), position.x, position.y, position.z);
        }

        switch (m_State)
        {
            case PickUp:
                Player::GetCharacter()->GetTaskInvoker().PlayAnimation("pickup_object", "pickup_low", 8.0f, -8.0f, -1, AF_DEFAULT, 0.0f, AIK_NONE);
                m_State = WaitForPickUp;
                break;
            case WaitForPickUp:
                if (ENTITY::IS_ENTITY_PLAYING_ANIM(Player::GetCharacter()->GetHandle(), "pickup_object", "pickup_low", 1)) return;
                m_State = PickedUp;
                break;
            case PickedUp:
                Sound(-1).PlayFrontend("PICKUP_DEFAULT", "HUD_FRONTEND_STANDARD_PICKUPS_SOUNDSET");
                m_State = None;
                break;
        }
    }
}