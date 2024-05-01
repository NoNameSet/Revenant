#pragma once

#include "CDisplayTextFormatting.h"
#include "Utils.h"

void CDisplayTextFormatting::InitialisePatterns()
{
    CScriptHud__ms_FormattingForNextDisplayText = GetRelativeReference<CDisplayTextFormatting>(
                                                    "48 8D 0D ? ? ? ? F3 0F 5C 0B", 3, 7);
}
