#ifndef REVENANT_THEFEED_H
#define REVENANT_THEFEED_H

#pragma once

#include "color32.h"

namespace revenant
{
    class TheFeed
    {
    public:
        static void Hide();
        static void HideNow();
        static void Show();
        static void Flush();
        static void Pause();
        static void Resume();
        static void Remove(int32_t handle);

        static void SetColor(HUD_COLOURS color);
        static void SetColor(rage::Color32 color);
        static void ResetAll();

        static int Post(const std::string& text, bool isImportant = true, bool cacheMessage = true);
        static int Post(const std::string& textureDictionary, const std::string& textureName, const std::string& title, const std::string& subtitle, const std::string& text, FEED_TEXT_ICON feedTextIcon = TEXT_ICON_BLANK, HUD_COLOURS hudColours = (HUD_COLOURS)-1);

        static bool IsPaused();
    };
}

#endif //REVENANT_THEFEED_H