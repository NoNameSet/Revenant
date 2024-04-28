#pragma once

#include "fwScriptGuid.h"
#include "Utils.h"

uintptr_t (*rage__fwScriptGuid__GetBaseFromGuid) (int32_t guid);
uint32_t (*rage__fwScriptGuid__CreateGuid) (uint64_t* base);

void fwScriptGuid::InitialisePatterns()
{
    ReadCall(
            hook::get_pattern(
                    "48 8B FA C6 44 24 ? ? E8 ? ? ? ? 48 8B D8 48 85 C0 74 41 48 8B D7", 8),
                        rage__fwScriptGuid__GetBaseFromGuid);

    ConvertCall(
            hook::get_pattern("48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 20 8B 15 ? ? ? ? 48 8B F9 48 83 C1 10 33 DB"),
                rage__fwScriptGuid__CreateGuid);
}

uintptr_t fwScriptGuid::GetBaseFromGuid(int32_t guid)
{
    return rage__fwScriptGuid__GetBaseFromGuid(guid);
}

uint32_t fwScriptGuid::CreateGuid(uint64_t *base)
{
    return rage__fwScriptGuid__CreateGuid(base);
}