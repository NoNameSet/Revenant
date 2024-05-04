#ifndef REVENANT_FWREFAWAREBASE_H
#define REVENANT_FWREFAWAREBASE_H

class datBase {
public:
    virtual ~datBase();
};
static_assert(sizeof(datBase) == 0x08);

namespace rage
{
    class fwKnownRefHolder
    {
    public:
        fwKnownRefHolder(void** ppReference, fwKnownRefHolder* pNext);

        void**					m_ppReference;
        fwKnownRefHolder*		m_pNext;
    };
    static_assert(sizeof(fwKnownRefHolder) == 0x10);

    template<class _Base> class fwRefAwareBaseImpl : public _Base
    {
    protected:
        mutable fwKnownRefHolder*	m_pKnownRefHolderHead;
    private:
        fwRefAwareBaseImpl( const fwRefAwareBaseImpl & )				{}
        fwRefAwareBaseImpl &operator=( const fwRefAwareBaseImpl & )		{ return *this; }
    };

    class fwRefAwareBase : public fwRefAwareBaseImpl<datBase>
    {
    };
    static_assert(sizeof(fwRefAwareBase) == 0x10);

    template <class T, class B = fwRefAwareBase>
    class fwRegdRef
    {
    public:
        T* m_p;
    };
}

#endif //REVENANT_FWREFAWAREBASE_H
