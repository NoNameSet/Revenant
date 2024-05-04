#ifndef REVENANT_PEDINVENTORY_H
#define REVENANT_PEDINVENTORY_H

#pragma once

#include "../weapons/Weapon.h"

namespace revenant
{
    class Ped;

    class PedInventory
    {
    public:
        PedInventory(Ped& owner);

        void SetCurrentWeapon(uint32_t hash);
        void RemoveAll();
        void Remove(uint32_t hash);
        void GiveWeapon(uint32_t hash, int ammo, bool forceIntoHand = false, bool equip = true);

        bool HasWeapon(uint32_t hash);

        std::unique_ptr<Weapon> GetCurrentWeapon();
        std::vector<std::unique_ptr<Weapon>> GetWeapons();
    private:
        Ped* const owner;
    };
}

#endif //REVENANT_PEDINVENTORY_H