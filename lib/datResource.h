#ifndef REVENANT_DATRESOURCE_H
#define REVENANT_DATRESOURCE_H

#pragma once

#include "sysAllocator.h"

class datResource {
public:
    datResource(void *containerLs,void *containerPpu,size_t containerSize) {
        m_Next = rage::tlsContext::get()->m_resource;
        rage::tlsContext::get()->m_resource = this;
        m_Fixup = (int)containerLs - (int)containerPpu;
        m_ContainerEa = (uint32_t)containerPpu;
        m_ContainerSize = containerSize;
    }
    ~datResource() {
        rage::tlsContext::get()->m_resource = m_Next;
    }
    bool ContainsThisAddress(const void *ptr) const {
        return (uint32_t)ptr - m_ContainerEa < m_ContainerSize;
    }
    template <class _Ptr> void PointerFixupNonNull(_Ptr& ptr) const {
        Assertf(ContainsThisAddress(ptr),"Pointer %p not in %x,%x",ptr,m_ContainerEa,m_ContainerSize);
        ptr = (_Ptr)((char*)(ptr) + m_Fixup);
    }
    template <class _Ptr> void PointerFixup(_Ptr& ptr) const {
#if __ASSERT
        if (ptr)
			PointerFixupNonNull(ptr);
#else
        ptr = (_Ptr)((char*)(ptr) + (ptr? m_Fixup : 0));
#endif
    }
    template <class _Ptr> static void Fixup(_Ptr &ptr) {
        datResource *curr = rage::tlsContext::get()->m_resource;
        if (ptr && curr)
            curr->PointerFixupNonNull(ptr);
    }
    template <class _Ptr> static void Place(_Ptr &ptr) {
        datResource *curr = rage::tlsContext::get()->m_resource;
        if (ptr && curr) {
            curr->PointerFixupNonNull(ptr);
            ptr->Place(ptr,*curr);
        }
    }
    template <class _Ptr,class _P1> static void Place(_Ptr &ptr,_P1 p1) {
        datResource *curr = rage::tlsContext::get()->m_resource;
        if (ptr && curr) {
            curr->PointerFixupNonNull(ptr);
            ptr->Place(ptr,*curr,p1);
        }
    }
    template <class _Ptr,class _P1,class _P2> static void Place(_Ptr &ptr,_P1 p1,_P2 p2) {
        datResource *curr = rage::tlsContext::get()->m_resource;
        if (ptr && curr) {
            curr->PointerFixupNonNull(ptr);
            ptr->Place(ptr,*curr,p1,p2);
        }
    }

    inline bool IsDefragmentation() const { return false; }
private:
    int m_Fixup;
    uint32_t m_ContainerEa, m_ContainerSize;
    datResource *m_Next;
} ;

#endif //REVENANT_DATRESOURCE_H