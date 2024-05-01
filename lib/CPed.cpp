#pragma once

#include "CPed.h"
#include "Utils.h"

bool (*CPed__HasHeadBlend) (CPed*);
void (*CPed__SetBehaviorFromTaskData) (CPed*);

void CPed::InitialisePatterns()
{
    ReadCall(
            hook::get_pattern(
                    "E8 ? ? ? ? 84 C0 74 2E 48 8B 0D ? ? ? ? 48 8B D3"),
                        CPed__HasHeadBlend);

    ConvertCall(
            hook::get_pattern(
                    "48 8B 41 20 48 8B D1 44 8B 88 ? ? ? ? 45 85 C9 74 32"),
                        CPed__SetBehaviorFromTaskData);
}

bool CPed::HasHeadBlend()
{
    return CPed__HasHeadBlend(this);
}

void CPed::SetBehaviorFromTaskData()
{
    return CPed__SetBehaviorFromTaskData(this);
}

CPedIntelligence *CPed::GetIntelligence()
{
    static uint32_t nIntelOffset =
            *hook::get_pattern<uint32_t>("4C 8B 81 ? ? ? ? 83 C8 FF", 3);

    return *(injector::raw_ptr(this) + nIntelOffset)
                .get<CPedIntelligence*>();
}

CQueriableInterface *CPedIntelligence::GetQueryableInterface()
{
    static uint32_t nQueryableInterfaceOffset =
            *hook::get_pattern<uint32_t>("48 8B 88 ? ? ? ? 48 85 C9 74 0A 8B 41 0C D1 E8 83 E0 07 EB 1B", 3);

    return reinterpret_cast<CQueriableInterface *>(this + nQueryableInterfaceOffset);
}