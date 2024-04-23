#pragma once

#include "fwScriptGuid.h"
#include "Utils.h"

uintptr_t (*rage__fwScriptGuid__GetBaseFromGuid) (int32_t guid);

void fwScriptGuid::InitialisePatterns()
{
    ReadCall(
            hook::get_pattern(
                    "48 8B FA C6 44 24 ? ? E8 ? ? ? ? 48 8B D8 48 85 C0 74 41 48 8B D7", 8),
                        rage__fwScriptGuid__GetBaseFromGuid);
}

uintptr_t fwScriptGuid::GetBaseFromGuid(int32_t guid)
{
    return rage__fwScriptGuid__GetBaseFromGuid(guid);
}