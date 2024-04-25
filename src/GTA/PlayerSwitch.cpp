#include "PlayerSwitch.h"

namespace revenant
{
    void PlayerSwitch::Start(const Ped &from, const Ped &to, SWITCH_FLAGS switchFlags, SWITCH_TYPE switchType)
    {
        STREAMING::START_PLAYER_SWITCH(from.GetHandle(), to.GetHandle(), static_cast<int>(switchFlags), static_cast<int>(switchType));
    }

    void PlayerSwitch::Start(const Ped &ped, SWITCH_FLAGS switchFlags, SWITCH_TYPE switchType)
    {
        STREAMING::SWITCH_TO_MULTI_FIRSTPART(ped.GetHandle(), static_cast<int>(switchFlags), static_cast<int>(switchType));
    }
}