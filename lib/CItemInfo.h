#ifndef REVENANT_CITEMINFO_H
#define REVENANT_CITEMINFO_H

#pragma once

#include "atArray.h"
#include "atFixedArray.h"
#include "atRTTI.h"
#include "fwRefAwareBase.h"
#include "flags.h"

class CPed;

class CWeaponObserver : public rage::fwRefAwareBase
{
public:
};

class CItemInfo : public rage::fwRefAwareBase
{
    DECLARE_RTTI_BASE_CLASS(CItemInfo);
public:
    rage::atHashValue m_Name;
    rage::atHashValue m_Model;
    rage::atHashValue m_Audio;
    rage::atHashValue m_Slot;
};
static_assert(sizeof(CItemInfo) == 0x20);

class CWeaponInfo : public CItemInfo
{
DECLARE_RTTI_DERIVED_CLASS(CWeaponInfo, CItemInfo);
public:
    static const int32_t MAX_ATTACH_POINTS = 7;
};

class CAmmoInfo : public CItemInfo
{
    DECLARE_RTTI_DERIVED_CLASS(CAmmoInfo, CItemInfo);
public:
    enum Flags
    {
        InfiniteAmmo = 0,
        AddSmokeOnExplosion	= 1,
        Fuse = 2,
        FixedAfterExplosion	= 3
    };

    enum SpecialType
    {
        None = 0,
        ArmorPiercing,
        Explosive,
        FMJ,
        HollowPoint,
        Incendiary,
        Tracer
    };

    int32_t m_AmmoMax;
    int32_t m_AmmoMax50;
    int32_t m_AmmoMax100;
    int32_t m_AmmoMaxMP;
    int32_t m_AmmoMax50MP;
    int32_t m_AmmoMax100MP;
    rage::fwFlags8 m_AmmoFlags;
    CAmmoInfo::SpecialType m_AmmoSpecialType;
};
static_assert(sizeof(CAmmoInfo) == 0x40);

class CInventoryItem
{
public:
    uint32_t m_uKey;
    rage::fwRegdRef<CItemInfo const, rage::fwRefAwareBase> m_pInfo;
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

enum WeaponComponentType
{
    WCT_Base,
    WCT_Clip,
    WCT_FlashLight,
    WCT_LaserSight,
    WCT_ProgrammableTargeting,
    WCT_Scope,
    WCT_Suppressor,
    WCT_VariantModel,
    WCT_Group,
};

class CWeaponBoneId
{
public:
    uint16_t m_BoneId;
};
static_assert(sizeof(CWeaponBoneId) == 0x02);

class CWeaponComponentInfo : public rage::fwRefAwareBase
{
DECLARE_RTTI_BASE_CLASS_WITH_ID(CWeaponComponentInfo, WCT_Base);
public:
    rage::atHashString m_Name;
    rage::atHashString m_Model;
    rage::atHashString m_LocName;
    rage::atHashString m_LocDesc;
    CWeaponBoneId m_AttachBone;
    int64_t* m_AccuracyModifier;
    int64_t* m_DamageModifier;
    int64_t* m_FallOffModifier;
    bool m_bShownOnWheel;
    bool m_CreateObject;
    bool m_ApplyWeaponTint;
    int8_t m_HudDamage;
    int8_t m_HudSpeed;
    int8_t m_HudCapacity;
    int8_t m_HudAccuracy;
    int8_t m_HudRange;
};

class CWeaponItem : public CInventoryItem
{
public:
    struct sComponent
    {
        int32_t attachPoint;
        const uint64_t* pComponentInfo;
        bool m_bActive;
        uint8_t m_uTintIndex;
    };
    typedef rage::atFixedArray<sComponent, CWeaponInfo::MAX_ATTACH_POINTS> Components;

    Components* m_pComponents;
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
    CAmmoInfo* m_pAmmoInfoOverride;
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

class CPedInventory : CWeaponObserver
{
public:
    CPed* m_pPed;
    CWeaponItemRepository m_weaponRepository;
    CAmmoItemRepository m_ammoRepository;
    uint32_t m_uCachedRechargeTime;
    uint32_t m_uCachedWeaponState;
};
static_assert(sizeof(CPedInventory) == 0x88);

#endif //REVENANT_CITEMINFO_H