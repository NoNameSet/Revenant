#ifndef REVENANT_FWEXTENSION_H
#define REVENANT_FWEXTENSION_H

class fwExtensionList
{
public:
    static uint64_t InternalGet(uint64_t list, uint32_t extensionId);

    static void InitialisePatterns();
};

#endif //REVENANT_FWEXTENSION_H