#ifndef REVENANT_COLOR32_H
#define REVENANT_COLOR32_H

namespace rage
{
    class Color32
    {
    public:
        Color32() { Set(255, 255, 255, 255); }
        Color32(uint32_t color) { m_Color = color; }
        Color32(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255) { Set(r, g, b, a); }

        [[nodiscard]] uint8_t GetRed() const { return (m_Color >> s_ChannelShiftR); }
        [[nodiscard]] uint8_t GetGreen() const { return (m_Color >> s_ChannelShiftG); }
        [[nodiscard]] uint8_t GetBlue() const { return (m_Color >> s_ChannelShiftB); }
        [[nodiscard]] uint8_t GetAlpha() const { return (m_Color >> s_ChannelShiftA); }
        [[nodiscard]] int32_t GetRGBA () const { return (GetRed() << 24) | (GetGreen() << 16) | (GetBlue() << 8) | (GetAlpha()); }
        uint8_t Clamp(int i) { return (i < 0 ? 0 : i > 255 ? 255 : (uint8_t)i); }

        void Set(int r, int g, int b, int a) { SetBytes(Clamp(r), Clamp(g), Clamp(b), Clamp(a)); }
        void SetBytes(uint8_t r, uint8_t g, uint8_t b, uint8_t a) { m_Color = (r << s_ChannelShiftR) | (g << s_ChannelShiftG) | (b << s_ChannelShiftB) | (a << s_ChannelShiftA); }
    public:
        static const int s_ChannelShiftA = 24;
        static const int s_ChannelShiftR = 16;
        static const int s_ChannelShiftG = 8;
        static const int s_ChannelShiftB = 0;

        uint32_t m_Color;
    };
}

#endif //REVENANT_COLOR32_H