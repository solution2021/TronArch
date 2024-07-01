﻿
#ifndef _RXRESOURCE_H_
#define _RXRESOURCE_H_
#pragma once

#include "zacbasedefs.h"
#include "PAL/api/zdef.h"
#include "zadesk.h"
#include "zpimplapi.h"
#include "zAcHeapOpers.h"




class ZcString;

#undef PAL
namespace ZwSoft { namespace ZwCAD {namespace PAL { class ZcRxResourceInstanceImp; } } }

class ZCBASE_PORT ZcRxResourceInstance
    : public Pimpl::ApiPart<ZcHeapOperators, ZwSoft::ZwCAD::PAL::ZcRxResourceInstanceImp>
{
public:
    explicit ZcRxResourceInstance(const wchar_t* path);
    
    ZcRxResourceInstance(void* hInst);

    ZcRxResourceInstance(const ZcRxResourceInstance& other);

    ~ZcRxResourceInstance();

    ZcRxResourceInstance(ZcRxResourceInstance&&) = delete;

    ZcRxResourceInstance& operator= (ZcRxResourceInstance&&) = delete;

    ZcRxResourceInstance& operator= (const ZcRxResourceInstance& other) = delete;

    bool tryLoadString(ZSoft::Int32 id, ZcString& out) const noexcept;
    bool isLoaded() const noexcept;
    
    bool loadDataResource(ZSoft::Int32 id, unsigned long& resourceSize, const void*& data) const noexcept;

    void freeDataResource(const void*& data) const noexcept;

    const static ZcRxResourceInstance& empty();
};
#endif 


