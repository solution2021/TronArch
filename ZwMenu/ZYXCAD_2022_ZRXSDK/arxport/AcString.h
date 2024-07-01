﻿
#ifndef __ACSTRING_H__
#define __ACSTRING_H__

#include "acbasedefs.h"
#include "adesk.h"
#include "AcHeapOpers.h"
#include "AdAChar.h"
#include "rxresource.h"
#include <cstdarg>

#include "../inc/zAcString.h"

#ifndef AcRxResourceInstance
#define AcRxResourceInstance	ZcRxResourceInstance
#endif //#ifndef AcRxResourceInstance   

#ifndef ACBASE_PORT
#define ACBASE_PORT		ZCBASE_PORT
#endif //#ifndef ACBASE_PORT

#ifndef AcUniqueString 
#define AcUniqueString 		ZcUniqueString 
#endif //#ifndef AcUniqueString 

#ifndef ACHAR
#define ACHAR		ZTCHAR
#endif //#ifndef ACHAR

#ifndef AcArray
#define AcArray		ZcArray
#endif //#ifndef AcArray

#ifndef AcArrayObjectCopyReallocator
#define AcArrayObjectCopyReallocator		ZcArrayObjectCopyReallocator
#endif //#ifndef AcArrayObjectCopyReallocator

#ifndef AcDbHandle
#define AcDbHandle		ZcDbHandle
#endif //#ifndef AcDbHandle

#ifndef AcHeapOperators
#define AcHeapOperators		ZcHeapOperators
#endif //#ifndef AcHeapOperators

#ifndef AcHeapOpers
#define AcHeapOpers		ZcHeapOpers
#endif //#ifndef AcHeapOpers

#ifndef AcString
#define AcString		ZcString
#endif //#ifndef AcString

#ifndef AcStringArray
#define AcStringArray		ZcStringArray
#endif //#ifndef AcStringArray

#ifndef AcStringImp
#define AcStringImp		ZcStringImp
#endif //#ifndef AcStringImp

#ifndef asAcDbHandle
#define asAcDbHandle		asZcDbHandle
#endif //#ifndef asAcDbHandle

#endif //#ifndef __ACSTRING_H__
