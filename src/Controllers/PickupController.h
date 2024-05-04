#ifndef REVENANT_PICKUPCONTROLLER_H
#define REVENANT_PICKUPCONTROLLER_H

#pragma once

#include "Script.h"
#include "GTA/entities/Prop.h"
#include "GTA/blip/Blip.h"

namespace revenant
{
    class PickupController : public Script
    {
    public:
        explicit PickupController() = default;
        ~PickupController() noexcept override = default;

        bool IsInitialized() override;
        void Initialize() override;
        void Destroy() override;
        void Tick() override;

    private:
        bool m_Initialized {};
        int m_LastPickupCreatedAt = MISC::GET_GAME_TIMER();
        std::vector<std::pair<Prop, Blip>> m_Pickups;
        const int MAX_PICKUP_COUNT = 1;
        const float PICKUP_DISPOSE_DISTANCE = 100.0f;
        const float PICKUP_COLLECT_DISTANCE = 1.8f;

        std::vector<std::tuple<std::string, std::string, std::function<void()>>> m_Choices;

        enum eState
        {
            None,
            PickUp,
            WaitForPickUp,
            PickedUp,
        };

        eState m_State = None;
    };

    inline std::shared_ptr<PickupController> g_PickupController;
}

#endif //REVENANT_PICKUPCONTROLLER_H