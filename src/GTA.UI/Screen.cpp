#include "Screen.h"

namespace revenant
{
    void Screen::DisplayHelp(const std::string &text, bool displayForever, bool playSound, int duration)
    {
        HUD::BEGIN_TEXT_COMMAND_DISPLAY_HELP("STRING");
        HUD::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text.c_str());
        HUD::END_TEXT_COMMAND_DISPLAY_HELP(0, displayForever, playSound, duration);
    }
}