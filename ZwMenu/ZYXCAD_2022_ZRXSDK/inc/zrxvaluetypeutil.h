﻿
#pragma once
#include "zrxmember.h"
#include "zrxvalue.h"
#include "zacarray.h"


template<typename ValueType>
class ZCBASE_PORT ZcRxValueTypePOD : public ZcRxValueType
{
public:

    ZcRxValueTypePOD(const ZTCHAR* name, ZcRxMemberCollectionConstructorPtr memberConstruct, void* userData = NULL):ZcRxValueType(name,sizeof(ValueType), memberConstruct, userData) {}

    ZcRxValueTypePOD(const ZTCHAR* name, const IZcRxEnumeration& pEnum, ZcRxMemberCollectionConstructorPtr memberConstruct, void* userData = NULL):ZcRxValueType(name,pEnum, sizeof(ValueType), memberConstruct, userData) {}

    ZcRxValueTypePOD(const ZTCHAR* name, const IZcRxReferenceType& pRef, ZcRxMemberCollectionConstructorPtr memberConstruct, void* userData = NULL):ZcRxValueType(name,pRef, sizeof(ValueType), memberConstruct, userData) {}
    
    virtual int subToString(const void* instance, ZTCHAR* buffer, size_t sizeInZTCHARs, ZcRxValueType::StringFormat format) const ZSOFT_OVERRIDE;
    virtual bool subEqualTo(const void* a, const void* b) const ZSOFT_OVERRIDE;
};

#ifdef __GNUC__
template<typename ValueType>
int ZcRxValueTypePOD<ValueType>::subToString(const void* instance, ZTCHAR* buffer, size_t sizeInZTCHARs, ZcRxValueType::StringFormat format) const
{
    return -1;
}
template<typename ValueType>
bool ZcRxValueTypePOD<ValueType>::subEqualTo(const void* a, const void* b) const
{
    return false;    
}
#endif

#pragma warning(push)

#pragma warning(disable: 4355) 
template<typename ValueType>
class ZcRxEnumType : public ZcRxValueTypePOD<ValueType>, public IZcRxEnumeration
{
    ZcArray<const ZcRxEnumTag*> m_tags;
public:
    ZcRxEnumType(const ZTCHAR* name, ZcRxMemberCollectionConstructorPtr memberConstruct, void* userData = NULL)
        :ZcRxValueTypePOD<ValueType>(name,*this, memberConstruct, userData) {}
    ~ZcRxEnumType()
    {
        for (int i=m_tags.length()-1;i>=0;i--)
            ZcRxMember::deleteMember(m_tags[i]);
    }
    virtual int count() const ZSOFT_OVERRIDE
    {
        return m_tags.length();
    }
    virtual const ZcRxEnumTag& getAt(int i) const ZSOFT_OVERRIDE
    {
        return *m_tags[i];
    }
    void append(ZcRxEnumTag& tag)
    {
        m_tags.append(&tag);
        void zcdbImpSetOwnerForEnumTag(const ZcRxClass*, ZcRxEnumTag*);
        zcdbImpSetOwnerForEnumTag(this, &tag);
    }
#ifdef __GNUC__
    virtual int subToString(const void* instance, ZTCHAR* buffer, size_t sizeInZTCHARs, ZcRxValueType::StringFormat format) const ZSOFT_OVERRIDE;
    virtual bool subEqualTo(const void* a, const void* b) const ZSOFT_OVERRIDE;
#endif    
};
#pragma warning(pop)

template<typename T>
class ZcRxNonBlittableType : public ZcRxValueType
{
    class NonBlittable : public IZcRxNonBlittableType
    {
        virtual void construct(void* dest, const void* source) const ZSOFT_OVERRIDE
        {
            ::new ((ZcRxValue*)dest) T(*(T*)source);
        }
        virtual void assign(void* dest, const void* source) const ZSOFT_OVERRIDE
        {
            ((T*)dest)->operator =(*(T*)source);
        }
        virtual void destruct(const void* instance) const ZSOFT_OVERRIDE
        {
            ((T*)instance)->~T();
        }
    } m_nonBlittable;
    virtual int subToString(const void* instance, ZTCHAR* buffer, size_t sizeInZTCHARs, ZcRxValueType::StringFormat format) const ZSOFT_OVERRIDE;
    virtual bool subEqualTo(const void* a, const void* b) const ZSOFT_OVERRIDE;
public:
    ZcRxNonBlittableType(const ZTCHAR* name, const ZTCHAR* parent, ZcRxMemberCollectionConstructorPtr memberConstruct, void* userData = NULL):ZcRxValueType(name, parent, m_nonBlittable,  sizeof(T), memberConstruct, userData) {}
    ZcRxNonBlittableType(const ZTCHAR* name, ZcRxMemberCollectionConstructorPtr memberConstruct, void* userData = NULL):ZcRxValueType(name,m_nonBlittable,  sizeof(T), memberConstruct, userData) {}
    ZcRxNonBlittableType(const ZTCHAR* name, const IZcRxEnumeration& enumeration, ZcRxMemberCollectionConstructorPtr memberConstruct, void* userData = NULL):ZcRxValueType(name, enumeration, m_nonBlittable, sizeof(T), memberConstruct, userData){}
    ZcRxNonBlittableType(const ZTCHAR* name, const IZcRxObjectValue& rxObjValue, ZcRxMemberCollectionConstructorPtr memberConstruct, void* userData = NULL):ZcRxValueType(name, rxObjValue, m_nonBlittable, sizeof(T), memberConstruct, userData){}
};

