#pragma once

#include "strPackfileManager.h"
#include "Patterns/Patterns.h"
#include "Utils.h"

int (*rage__strPackfileManager__RegisterIndividualFile) (int*, const char*, bool, const char*, bool, bool);

void
strPackfileManager::InitialisePatterns()
{
    ConvertCall(
            hook::get_pattern(
                    "48 89 5C 24 ? 48 89 6C 24 ? 48 89 7C 24 ? 41 54 41 56 41 57 48 83 EC 50 48 8B EA 4C 8B FA 48 8B D9 4D 85 C9 B2 01 48 8B CD 45 8A E0 4D 0F 45 F9 E8 ? ? ? ? 48 8B F8"),
                        rage__strPackfileManager__RegisterIndividualFile);
}

int
strPackfileManager::RegisterIndividualFile(int *result, const char *file, bool quitOnBadVersion, const char *relativePath, bool quitIfMissing, bool overlayIfExists)
{
    return rage__strPackfileManager__RegisterIndividualFile(result, file, quitOnBadVersion, relativePath, quitIfMissing, overlayIfExists);
}