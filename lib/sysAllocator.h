#ifndef REVENANT_SYSALLOCATOR_H
#define REVENANT_SYSALLOCATOR_H

#include "atRTTI.h"

class datResource;

namespace rage
{
    class sysMemAllocator
    {
    public:
        virtual ~sysMemAllocator() = 0;
        virtual void SetQuitOnFail(bool quitOnFail) = 0;
        virtual void *Allocate(std::size_t size, std::size_t align, int heapIndex) = 0;
        virtual void *TryAllocate(std::size_t size, std::size_t align, int heapIndex) = 0;
        virtual void Free(void *pointer) = 0;
        virtual void TryFree(void *ptr) = 0;
        virtual void Resize(void *pointer, std::size_t size) = 0;
        virtual sysMemAllocator *GetAllocator(int heapIndex) const = 0;
        virtual sysMemAllocator *GetAllocator(int heapIndex) = 0;
        virtual sysMemAllocator *GetPointerOwner(void *ptr) = 0;
        virtual std::size_t GetSize(void *ptr) const = 0;
        virtual std::size_t GetMemoryUsed(int bucket) = 0;
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
        datResource* m_resource; // 0x190 // datResource

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