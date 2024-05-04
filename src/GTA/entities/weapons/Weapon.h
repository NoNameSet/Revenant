#ifndef REVENANT_WEAPON_H
#define REVENANT_WEAPON_H

#pragma once

namespace revenant
{
    class Ped;

    class Weapon
    {
    public:
        Weapon(Ped& owner, uint32_t weaponHash);

        [[nodiscard]] bool IsValid() const;

    private:
        Ped* owner;
        uint32_t weaponHash;
    };
}

#endif //REVENANT_WEAPON_H