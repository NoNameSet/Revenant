#ifndef REVENANT_CPED_H
#define REVENANT_CPED_H

#pragma once

#include "CItemInfo.h"

class CQueriableInterface
{
public:
    char pad_0000[32];
    int m_iScriptCommand;
    int m_iScriptTaskStage;
};
static_assert(sizeof(CQueriableInterface) == 0x28);

class CPedIntelligence
{
public:
    CQueriableInterface* GetQueryableInterface();
};

class CPed
{
public:
    bool HasHeadBlend();
    void SetBehaviorFromTaskData();
    CPedIntelligence* GetIntelligence();
    CPedInventory* GetInventory();

    static void InitialisePatterns();
};

#endif //REVENANT_CPED_H