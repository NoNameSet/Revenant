#ifndef REVENANT_PICKUPCONTROLLER_H
#define REVENANT_PICKUPCONTROLLER_H

#pragma once

#include "Script.h"

namespace revenant
{
    class PickupController : public Script
    {
    public:
        explicit PickupController() = default;
        ~PickupController() noexcept = default;

        bool IsInitialized() override;
        void Initialize() override;
        void Destroy() override;
        void Tick() override;
    private:
        bool m_Initialized {};
    };

    inline std::shared_ptr<PickupController> g_PickupController;
}

#endif //REVENANT_PICKUPCONTROLLER_H