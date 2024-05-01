#ifndef REVENANT_RAGE_H
#define REVENANT_RAGE_H

#pragma once

namespace rage
{
    enum atHashStringNamespaces
    {
        HSNS_ATHASHSTRING,
        HSNS_ATFINALHASHSTRING,
        HSNS_ATLITERALHASHSTRING,
        HSNS_DIAGSTRING,
        HSNS_STATNAMESTRING,
        HSNS_NUM_NAMESPACES,
        HSNS_INVALID = 255,
        HSNS_MAX_NAMESPACES = 256,
    };

    struct atHashStringStats
    {
        uint32_t m_refdStringCount;
        uint32_t m_refdStringChars;
    };

    class atNamespacedHashStringBase
    {
    public:
        void SetHash(const uint32_t hash)					{ m_hash = hash; }
        uint32_t GetHash() const								{ return m_hash; }
        void Clear()									{ m_hash = 0; }
        bool IsNull() const								{ return m_hash == 0; }
        bool IsNotNull() const							{ return m_hash != 0; }

    protected:
        uint32_t 		m_hash;
    };

    template<atHashStringNamespaces Namespace>
    class atNamespacedHashValue : public atNamespacedHashStringBase
    {
    public:
    };

    class atHashValue : public atNamespacedHashValue<HSNS_ATHASHSTRING>
    {
        typedef atNamespacedHashValue<HSNS_ATHASHSTRING> Base;
    public:
        atHashValue() : Base() {}

        // Define operator== and operator!= for comparing with atHashValue
        bool operator==(const atHashValue& other) const {
            return m_hash == other.m_hash;
        }

        bool operator!=(const atHashValue& other) const {
            return m_hash != other.m_hash;
        }

        static atHashValue Null() { return atHashValue(); }
        static const char* TryGetString(const uint32_t hash) { return nullptr; }
    };

    class atHashString
    {
    public:
        atHashString() : m_hash(0) {}

        // Define operator== and operator!= for comparing with atHashString
        bool operator==(const atHashString& other) const {
            return m_hash == other.m_hash;
        }

        bool operator!=(const atHashString& other) const {
            return m_hash != other.m_hash;
        }

        const char* GetCStr() const { return nullptr; }
        const char* TryGetCStr() const { return nullptr; }
        uint32_t GetLength() const { return 0; }
        static const char* TryGetString(const uint32_t hash) { return nullptr; }
        static atHashStringStats GetStats() { return atHashStringStats(); }
        static atHashString Null() { return atHashString(); }

    protected:
        uint32_t m_hash;
    };

    class atLiteralHashString : public atHashString
    {
    public:
        atLiteralHashString() : atHashString() {}

        // Define operator== and operator!= for comparing with atLiteralHashString
        bool operator==(const atLiteralHashString& other) const {
            return m_hash == other.m_hash;
        }

        bool operator!=(const atLiteralHashString& other) const {
            return m_hash != other.m_hash;
        }

        // Dummy implementations of other member functions
        explicit atLiteralHashString(const uint32_t hash) : atHashString() {}
        explicit atLiteralHashString(const char* str) : atHashString() {}
        atLiteralHashString(const char* str, const uint32_t hash) : atHashString() {}
    };
}

#endif //REVENANT_RAGE_H