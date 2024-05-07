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

        bool operator==(const atHashValue& other) const
        {
            return m_hash == other.m_hash;
        }

        bool operator!=(const atHashValue& other) const
        {
            return m_hash != other.m_hash;
        }
    };

    class atHashString
    {
    public:
        atHashString() : m_hash(0) {}

        bool operator==(const atHashString& other) const
        {
            return m_hash == other.m_hash;
        }

        bool operator!=(const atHashString& other) const
        {
            return m_hash != other.m_hash;
        }

    public:
        uint32_t m_hash;
    };

    class atLiteralHashString : public atHashString
    {
    public:
        atLiteralHashString() : atHashString() {}

        bool operator==(const atLiteralHashString& other) const
        {
            return m_hash == other.m_hash;
        }

        bool operator!=(const atLiteralHashString& other) const
        {
            return m_hash != other.m_hash;
        }
    };
}

#endif //REVENANT_RAGE_H