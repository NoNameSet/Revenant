#include "Player.h"
#include "fwScriptGuid.h"
#include "CGameWorld.h"

namespace revenant
{
    std::unique_ptr<Ped> Player::GetCharacter()
    {
        return std::make_unique<Ped>(fwScriptGuid::CreateGuid(reinterpret_cast<uint64_t*>(CGameWorld::FindPlayer())));
    }
}