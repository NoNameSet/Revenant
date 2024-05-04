#include "PedInventory.h"
#include "Ped.h"

namespace revenant
{
    PedInventory::PedInventory(Ped &owner) : owner(&owner)
    {
    }

    void PedInventory::SetCurrentWeapon(uint32_t hash)
    {
        WEAPON::SET_CURRENT_PED_WEAPON(this->owner->GetHandle(), hash, true);
    }

    void PedInventory::RemoveAll()
    {
        WEAPON::REMOVE_ALL_PED_WEAPONS(this->owner->GetHandle(), false);
    }

    void PedInventory::Remove(uint32_t hash)
    {
        WEAPON::REMOVE_WEAPON_FROM_PED(this->owner->GetHandle(), hash);
    }

    void PedInventory::GiveWeapon(uint32_t hash, int ammo, bool forceIntoHand, bool equip)
    {
        WEAPON::GIVE_WEAPON_TO_PED(this->owner->GetHandle(), hash, ammo, forceIntoHand, equip);
    }

    bool PedInventory::HasWeapon(uint32_t hash)
    {
        return WEAPON::HAS_PED_GOT_WEAPON(this->owner->GetHandle(), hash, false);
    }

    std::unique_ptr<Weapon> PedInventory::GetCurrentWeapon()
    {
        uint32_t hash;
        WEAPON::GET_CURRENT_PED_WEAPON(this->owner->GetHandle(), &hash, false);
        return std::make_unique<Weapon>(*this->owner, hash);
    }

    std::vector<std::unique_ptr<Weapon>> PedInventory::GetWeapons()
    {
        auto weapons = std::vector<std::unique_ptr<Weapon>>();

        CPed* pPed = (CPed*)this->owner->GetMemoryAddress();

        if (pPed == nullptr)
            return weapons;

        auto items = pPed->GetInventory()->m_weaponRepository.m_items;

        for (int i = 0; i < items.count(); i++)
        {
            weapons.push_back(std::make_unique<Weapon>(*this->owner, items[i]->m_pInfo.m_p->m_Name.m_hash));
        }

        return weapons;
    }
}