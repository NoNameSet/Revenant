#ifndef REVENANT_FWSCRIPTGUID_H
#define REVENANT_FWSCRIPTGUID_H

class fwScriptGuid
{
public:
    static uintptr_t GetBaseFromGuid(int32_t guid);
    static uint32_t CreateGuid(uint64_t* base);

    static void InitialisePatterns();
};

#endif //REVENANT_FWSCRIPTGUID_H