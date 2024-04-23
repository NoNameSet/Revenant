#pragma once

#include "CPedHeadBlendData.h"
#include "Utils.h"
#include "fwExtension.h"

void CPedHeadBlendData::InitialisePatterns()
{
    CPedHeadBlendData__AutoId__m_Id = GetRelativeReference<uint32_t>(
            "48 39 5E 38 74 1B 8B 15 ? ? ? ? 48 8D 4F 10 E8", 8, 12);
}

CPedHeadBlendData* CPedHeadBlendData::GetHeadBlendData(CPed *pPed)
{
    if (pPed->HasHeadBlend())
    {
        return reinterpret_cast<CPedHeadBlendData *>(fwExtensionList::InternalGet(reinterpret_cast<uint64_t>(pPed + 0x10), *CPedHeadBlendData__AutoId__m_Id));
    }

    return nullptr;
}