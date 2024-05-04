#include "Weapon.h"
#include "../peds/Ped.h"

namespace revenant
{
    Weapon::Weapon(revenant::Ped &owner, uint32_t weaponHash) : owner(&owner), weaponHash(weaponHash)
    {
    }

    bool Weapon::IsValid() const
    {
        return WEAPON::IS_WEAPON_VALID(this->weaponHash);
    }
}