#ifndef REVENANT_CITEMINFO_H
#define REVENANT_CITEMINFO_H

#pragma once

#include "atArray.h"
#include "atRTTI.h"

class CItemInfo
{
    DECLARE_RTTI_BASE_CLASS(CItemInfo);
public:
};

class CAmmoInfo : public CItemInfo
{
    DECLARE_RTTI_DERIVED_CLASS(CAmmoInfo, CItemInfo);
public:
};

class CInventoryItem
{
public:
    uint32_t m_uKey;
    int64_t m_pInfo;
    uint32_t m_uModelHashOverride;
    int64_t m_assetRequester;
};
static_assert(sizeof(CInventoryItem) == 0x20);

class CAmmoItem
{
public:
    int32_t m_iAmmo;
    bool m_bUsingInfiniteAmmo;
    bool m_bIgnoreInfiniteAmmoFlag;
};

class CWeaponItem : public CInventoryItem
{
public:
    uint64_t m_pComponents;
    uint64_t m_pAssetRequesterAnim;
    uint64_t m_pAssetRequesterComponent;
    uint64_t m_pAssetRequesterAmmo;
    uint64_t m_pAssetRequesterWhenEquipped;
    uint32_t m_uTimer;
    uint8_t m_uTintIndex;
    uint8_t m_uCachedWeaponTintIndex;
    bool	m_bCachedWeaponTint;
    bool	m_bCanSelect;
    int32_t m_iLastAmmoInClip;
    int64_t m_pAmmoInfoOverride;
    uint32_t m_uCachedWeaponState;
};
static_assert(sizeof(CWeaponItem) == 0x68);

template <typename _Item, int32_t _MaxStorage>
class CInventoryItemRepository
{
public:
    rage::atArray<_Item*> m_items;
    char pad_0010[32];
};
static_assert(sizeof(CInventoryItemRepository<CWeaponItem, 105>) == 0x30);

static const int32_t MAX_WEAPONS = 105;

class CWeaponItemRepository : public CInventoryItemRepository<CWeaponItem, MAX_WEAPONS>
{
};

static const int32_t MAX_AMMOS = 65;

class CAmmoItemRepository : public CInventoryItemRepository<CAmmoItem, MAX_AMMOS>
{
public:
    bool m_bUsingInfiniteAmmo	: 1;
    bool m_bUsingInfiniteClips	: 1;
};

#endif //REVENANT_CITEMINFO_H