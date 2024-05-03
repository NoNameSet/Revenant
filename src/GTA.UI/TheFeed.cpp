#include "TheFeed.h"

namespace revenant
{
    void TheFeed::Hide()
    {
        HUD::THEFEED_HIDE();
    }

    void TheFeed::HideNow()
    {
        HUD::THEFEED_HIDE_THIS_FRAME();
    }

    void TheFeed::Show()
    {
        HUD::THEFEED_SHOW();
    }

    void TheFeed::Flush()
    {
        HUD::THEFEED_FLUSH_QUEUE();
    }

    void TheFeed::Pause()
    {
        HUD::THEFEED_PAUSE();
    }

    void TheFeed::Resume()
    {
        HUD::THEFEED_RESUME();
    }

    void TheFeed::Remove(int32_t handle)
    {
        HUD::THEFEED_REMOVE_ITEM(handle);
    }

    void TheFeed::SetColor(HUD_COLOURS color)
    {
        HUD::THEFEED_SET_BACKGROUND_COLOR_FOR_NEXT_POST(static_cast<int>(color));
    }

    void TheFeed::SetColor(rage::Color32 color)
    {
        HUD::THEFEED_SET_RGBA_PARAMETER_FOR_NEXT_MESSAGE(color.GetRed(), color.GetGreen(), color.GetBlue(), color.GetAlpha());
    }

    void TheFeed::ResetAll()
    {
        HUD::THEFEED_RESET_ALL_PARAMETERS();
    }

    int TheFeed::Post(const std::string &text, bool isImportant, bool cacheMessage)
    {
        HUD::BEGIN_TEXT_COMMAND_THEFEED_POST("STRING");
        HUD::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text.c_str());
        return HUD::END_TEXT_COMMAND_THEFEED_POST_TICKER_WITH_TOKENS(isImportant, cacheMessage);
    }

    int TheFeed::Post(const std::string &textureDictionary, const std::string &textureName, const std::string &title, const std::string &subtitle, const std::string &text, FEED_TEXT_ICON feedTextIcon, HUD_COLOURS hudColours)
    {
        if (!GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED(textureDictionary.c_str()))
            GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT(textureDictionary.c_str(), true);

        HUD::BEGIN_TEXT_COMMAND_THEFEED_POST("STRING");

        if (hudColours != (HUD_COLOURS)-1)
            SetColor(hudColours);

        HUD::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text.c_str());
        return HUD::END_TEXT_COMMAND_THEFEED_POST_MESSAGETEXT(textureDictionary.c_str(), textureName.c_str(), true, static_cast<int>(feedTextIcon), title.c_str(), subtitle.c_str());
    }

    bool TheFeed::IsPaused()
    {
        return HUD::THEFEED_IS_PAUSED();
    }
}