#ifndef REVENANT_FLAGS_H
#define REVENANT_FLAGS_H

namespace rage
{
    template<typename T>
    class fwFlags
    {
    public:

        fwFlags() : m_flags(0) {}
        fwFlags(T flags) : m_flags(flags) {}

        void SetFlag(T flag) { m_flags |= flag; }
        void SetAllFlags(T flag = ~(T())) { m_flags = flag; }
        bool ClearFlag(T flag) { return (m_flags &= ~flag) != 0; }
        void ClearAllFlags() { m_flags = 0; }
        void ChangeFlag(T flag, bool bVal) { if( bVal ) { SetFlag(flag); } else { ClearFlag(flag); } }
        void ToggleFlag(T flag) { m_flags ^= flag; }

        bool IsFlagSet(T flag) const { return (m_flags & flag)!=0; }
        bool AreAllFlagsSet(T flags) const { return (m_flags & flags)==flags; }
        T GetAllFlags() const { return m_flags; }

        // Operators
        operator T() const { return m_flags; }

    private:
        T m_flags;
    };

    typedef fwFlags<uint8_t>  fwFlags8;
    typedef fwFlags<uint16_t> fwFlags16;
    typedef fwFlags<int32_t> fwFlags32;
    typedef fwFlags<uint64_t> fwFlags64;
}

#endif //REVENANT_FLAGS_H