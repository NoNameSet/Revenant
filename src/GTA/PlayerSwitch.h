#ifndef REVENANT_PLAYERSWITCH_H
#define REVENANT_PLAYERSWITCH_H

#pragma once

#include "entities/peds/Ped.h"

namespace revenant
{
    class PlayerSwitch
    {
    public:
        static void Start(const Ped& from, const Ped& to, SWITCH_FLAGS switchFlags, SWITCH_TYPE switchType);
        static void Start(const Ped& ped, SWITCH_FLAGS switchFlags, SWITCH_TYPE switchType);
    };
}

#endif //REVENANT_PLAYERSWITCH_H