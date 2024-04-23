#ifndef REVENANT_CTASKDATAINFO_H
#define REVENANT_CTASKDATAINFO_H

#include "rage.h"
#include "atArray.h"
#include "CPed.h"

class CTaskDataInfo
{
public:
    uint32_t m_Name;
    uint32_t m_TaskWanderConditionalAnimsGroup;
    float m_ScenarioAttractionDistance;
    float m_SurfaceSwimmingDepthOffset;
    float m_SwimmingWanderPointRange;
    bool m_PreferCurrentDepthInSwimmingWander;
    int m_Flags;
};

class CTaskDataInfoManager
{
public:
    rage::atArray<CTaskDataInfo*> m_aTaskData;
    CTaskDataInfo* m_DefaultSet;

    inline static CTaskDataInfoManager* m_TaskDataManagerInstance;
    inline static uint32_t* CPedModelInfo__m_TaskDataHash;

    static CTaskDataInfo* Create(const char* name, eTaskDataInfoFlags flags);
    static void Update(const char* name, eTaskDataInfoFlags flags);
    static bool IsValid(const char* name);
    static void Apply(CPed* ped, const char* name);

    static void InitialisePatterns();
};



#endif //REVENANT_CTASKDATAINFO_H