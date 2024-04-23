#ifndef REVENANT_SYSALLOCATOR_H
#define REVENANT_SYSALLOCATOR_H

#include "atRTTI.h"

namespace rage
{
    class sysMemAllocator
    {
    public:
        DEFINE_RAGE_RTTI(rage::sysMemAllocator);

        virtual void SetQuitOnFail(bool) = 0;
        virtual void *Allocate(std::size_t size, std::size_t align, int subAllocator) = 0;
        virtual void *TryAllocate(std::size_t size, std::size_t align, int subAllocator) = 0;
        virtual void Free(void *pointer) = 0;
        virtual void TryFree(void *pointer) = 0;
        virtual void Resize(void *pointer, std::size_t size) = 0;
        virtual sysMemAllocator *GetAllocator(int allocator) const = 0;
        virtual sysMemAllocator *GetAllocator(int allocator) = 0;
        virtual sysMemAllocator *GetPointerOwner(void *pointer) = 0;
        virtual std::size_t GetSize(void *pointer) const = 0;
        virtual std::size_t GetMemoryUsed(int memoryBucket) = 0;
        virtual std::size_t GetMemoryAvailable() = 0;
    };
}

namespace rage
{
#pragma pack(push, 1)
    class tlsContext
    {
    public:
        char gap0[180];
        std::uint8_t m_unk_byte; // 0xB4
        char gapB5[3];
        sysMemAllocator *m_allocator; // 0xB8
        sysMemAllocator *m_allocator2; // 0xC0 - Same as 0xB8
        sysMemAllocator *m_allocator3; // 0xC8 - Same as 0xB8
        uint32_t m_console_smth; // 0xD0
        char gapD4[188];
        uint64_t m_unk; // 0x190

#if _WIN32
        static tlsContext* get()
        {
            constexpr std::uint32_t TlsIndex = 0x0;
            return *reinterpret_cast<tlsContext**>(__readgsqword(0x58) + TlsIndex);
        }
#endif
    };
#pragma pack(pop)
}

#endif //REVENANT_SYSALLOCATOR_H