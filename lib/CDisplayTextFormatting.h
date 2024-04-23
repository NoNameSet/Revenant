#ifndef REVENANT_CDISPLAYTEXTFORMATTING_H
#define REVENANT_CDISPLAYTEXTFORMATTING_H

class CDisplayTextFormatting
{
public:
    uint32_t m_Color;
    float m_XScale;
    float m_YScale;
    float m_WrapStartX;
    float m_WrapEndX;
    int m_FontStyle;
    int m_WidescreenFormat;
    int8_t m_Justification;
    int8_t m_Leading;
    bool m_bDropShadow;
    bool m_bOutline;
    char pad_0020[8];
};

static_assert(sizeof(CDisplayTextFormatting) == 0x28);

#endif //REVENANT_CDISPLAYTEXTFORMATTING_H