#ifndef REVENANT_DATRESOURCE_H
#define REVENANT_DATRESOURCE_H

#pragma once

#include "sysAllocator.h"

class datResource {
public:
    datResource(void *containerLs,void *containerPpu,size_t containerSize)
    {
        m_Next = rage::tlsContext::get()->m_resource;
        rage::tlsContext::get()->m_resource = this;
        m_Fixup = (int)containerLs - (int)containerPpu;
        m_ContainerEa = (uint32_t)containerPpu;
        m_ContainerSize = containerSize;
    }

    ~datResource()
    {
        rage::tlsContext::get()->m_resource = m_Next;
    }

    bool ContainsThisAddress(const void *ptr) const
    {
        return (uint32_t)ptr - m_ContainerEa < m_ContainerSize;
    }

    template <class T> void PointerFixupNonNull(T& ptr) const
    {
        ptr = (T)((char*)(ptr) + m_Fixup);
    }

    template <class T> void PointerFixup(T& ptr) const
    {
        ptr = (T)((char*)(ptr) + (ptr? m_Fixup : 0));
    }

    template <class T> static void Fixup(T &ptr) {
        datResource *curr = rage::tlsContext::get()->m_resource;
        if (ptr && curr)
            curr->PointerFixupNonNull(ptr);
    }

    template <class T> static void Place(T &ptr)
    {
        datResource *curr = rage::tlsContext::get()->m_resource;
        if (ptr && curr) {
            curr->PointerFixupNonNull(ptr);
            ptr->Place(ptr,*curr);
        }
    }

    template <class T1,class T2> static void Place(T1 &ptr, T2 p1)
    {
        datResource *curr = rage::tlsContext::get()->m_resource;
        if (ptr && curr) {
            curr->PointerFixupNonNull(ptr);
            ptr->Place(ptr,*curr,p1);
        }
    }

    template <class T1,class T2,class T3> static void Place(T1 &ptr, T2 p1, T3 p2)
    {
        datResource *curr = rage::tlsContext::get()->m_resource;
        if (ptr && curr) {
            curr->PointerFixupNonNull(ptr);
            ptr->Place(ptr,*curr,p1,p2);
        }
    }

private:
    int m_Fixup;
    uint32_t m_ContainerEa, m_ContainerSize;
    datResource *m_Next;
} ;

#endif //REVENANT_DATRESOURCE_H