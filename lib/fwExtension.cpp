#pragma once

#include "fwExtension.h"
#include "Utils.h"

uint64_t (*rage__fwExtensionList__InternalGet) (uint64_t, uint32_t);

void
fwExtensionList::InitialisePatterns()
{
    ConvertCall(
            hook::get_pattern(
                    "48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 20 8B FA 83 FA 20"),
                        rage__fwExtensionList__InternalGet);
}

uint64_t fwExtensionList::InternalGet(uint64_t list, uint32_t extensionId)
{
    return rage__fwExtensionList__InternalGet(list, extensionId);
}