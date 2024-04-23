#ifndef REVENANT_SCREEN_H
#define REVENANT_SCREEN_H

namespace revenant
{
    class Screen
    {
    public:
        static void DisplayHelp(const std::string& text, bool displayForever = true, bool playSound = true, int duration = -1);
    };
}

#endif //REVENANT_SCREEN_H