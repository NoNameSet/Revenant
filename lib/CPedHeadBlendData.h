#ifndef REVENANT_CPEDHEADBLENDDATA_H
#define REVENANT_CPEDHEADBLENDDATA_H

#include "CPed.h"

#define MAX_PALETTE_COLORS (4)

class CPedHeadBlendData
{
public:
    char pad_0000[40];
    float m_headBlend;
    float m_texBlend;
    float m_varBlend;
    float m_parentBlend2;
    float m_overlayAlpha[HOS_MAX];
    float m_overlayNormAlpha[HOS_MAX];
    float m_microMorphBlends[MMT_MAX];
    uint8_t m_overlayTintIndex[HOS_MAX];
    uint8_t m_overlayTintIndex2[HOS_MAX];
    uint8_t m_overlayRampType[HOS_MAX];
    uint8_t m_head0;
    uint8_t m_head1;
    uint8_t m_head2;
    uint8_t m_tex0;
    uint8_t m_tex1;
    uint8_t m_tex2;
    uint8_t m_overlayTex[HOS_MAX];
    uint8_t m_paletteRed[MAX_PALETTE_COLORS];
    uint8_t m_paletteGreen[MAX_PALETTE_COLORS];
    uint8_t m_paletteBlue[MAX_PALETTE_COLORS];
    uint16_t m_eyeColor;
    uint8_t m_hairTintIndex;
    uint8_t m_hairTintIndex2;
    bool m_async;
    bool m_usePaletteRgb;
    bool m_hasParents;
    bool m_isParent;
    bool m_needsFinalizing;

    inline static uint32_t* CPedHeadBlendData__AutoId__m_Id;
    static CPedHeadBlendData* GetHeadBlendData(CPed* pPed);
    static void InitialisePatterns();
};

#endif //REVENANT_CPEDHEADBLENDDATA_H