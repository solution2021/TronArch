

#ifndef ZC_RXBOILER_H
#define ZC_RXBOILER_H

#include "zAdAChar.h"
#include "zrxnames.h"
#include "zacbasedefs.h"
#pragma pack (push, 8)

class ZcRxClass;

ZCBASE_PORT ZcRxClass * zcrxFindZcRxClass(const ZTCHAR *pClassName);

#define ZCRX_AUTO_INIT_QUEUE_EXPR(CLASS_NAME) zcrxQueueClassForInitialization(&CLASS_NAME::gpDesc, &CLASS_NAME::rxInit)

#ifdef ZCRX_AUTO_INIT 
#define ZCRX_AUTO_INIT_DEFAULT(CLASS_NAME) ZCRX_AUTO_INIT_QUEUE_EXPR(CLASS_NAME)
#else
#define ZCRX_AUTO_INIT_DEFAULT(CLASS_NAME) nullptr
#endif

#define ZCRX_DEFINE_GPDESC(CLASS_NAME, AUTOINIT) \
    ZcRxClass* CLASS_NAME::gpDesc = AUTOINIT(CLASS_NAME);

#define ZCRX_DECLARE_GPDESC(CLASS_NAME) \
    static ZcRxClass* gpDesc; 

class ZcRxObject;
template <typename T>
static ZcRxObject* zcrxInstantiateClass() { return new T();}


#define ZCRX_DECLARE_MEMBERS_EXPIMP(CLASS_NAME, EXPIMP) \
    friend ZcRxObject* ::zcrxInstantiateClass<CLASS_NAME>(); \
	EXPIMP virtual ZcRxClass* isA() const ZSOFT_OVERRIDE; \
    ZCRX_DECLARE_GPDESC(CLASS_NAME); \
	EXPIMP static ZcRxClass* desc(); \
	static CLASS_NAME* cast(const ZcRxObject* inPtr) \
{ return ((inPtr == NULL) || !inPtr->isKindOf(CLASS_NAME::desc())) \
	? NULL : (CLASS_NAME*)inPtr; }; \
	static void rxInit(); \
	static void rxInit(AppNameChangeFuncPtr)

#define ZCRX_EMPTY

#define ZCRX_DECLARE_MEMBERS(CLASS_NAME) \
	ZCRX_DECLARE_MEMBERS_EXPIMP(CLASS_NAME, ZCRX_EMPTY )

#define ZCRX_DEFINE_MEMBERS_WORKER(CLASS_NAME, AUTOINIT) \
	ZcRxClass* CLASS_NAME::desc() \
{ \
	if (gpDesc == nullptr) \
	gpDesc = ::zcrxFindZcRxClass(ZCRX_T(#CLASS_NAME)); \
	return gpDesc; \
} \
	ZcRxClass* CLASS_NAME::isA() const \
{ \
	if (gpDesc == nullptr) \
	gpDesc = ::zcrxFindZcRxClass(ZCRX_T(#CLASS_NAME)); \
	return gpDesc; \
} \
ZCRX_DEFINE_GPDESC(CLASS_NAME, AUTOINIT)

#define ZCRX_DEFINE_MEMBERS(CLASS_NAME) \
ZCRX_DEFINE_MEMBERS_WORKER(CLASS_NAME, ZCRX_AUTO_INIT_DEFAULT)


#include "zAdAChar.h"

extern "C" void ZCBASE_PORT zcrx_abort (const ZTCHAR * format, ...);
#define ZCRX_STATIC_CHECK(CLASS_NAME) \
	if (gpDesc!=nullptr) { \
	ZcRxClass *pClass = ::zcrxFindZcRxClass(ZCRX_T(#CLASS_NAME)); \
	if (pClass) { \
	if (gpDesc == pClass) \
	return; \
			else \
			zcrx_abort(ZCRX_T("Class mismatch")); \
		} \
	}

#define ZCRX_NO_CONS_DEFINE_MEMBERS_WORKER(AUTOINIT,CLASS_NAME,PARENT_CLASS,PARENT_CLASS_STR) \
ZCRX_DEFINE_MEMBERS_WORKER(CLASS_NAME, AUTOINIT); \
void CLASS_NAME::rxInit() { \
    ZCRX_STATIC_CHECK(CLASS_NAME); \
    gpDesc = newZcRxClass(ZCRX_T(#CLASS_NAME), ZCRX_T(PARENT_CLASS_STR)); \
}

#define ZCRX_NO_CONS_DEFINE_MEMBERS(CLASS_NAME,PARENT_CLASS) \
	ZCRX_NO_CONS_DEFINE_MEMBERS_WORKER(ZCRX_AUTO_INIT_DEFAULT,CLASS_NAME, PARENT_CLASS, #PARENT_CLASS)


#define ZCRX_NO_CONS_DEFINE_MEMBERS_AUTO(CLASS_NAME,PARENT_CLASS) \
	ZCRX_NO_CONS_DEFINE_MEMBERS_WORKER(ZCRX_AUTO_INIT_QUEUE_EXPR, CLASS_NAME,PARENT_CLASS, #PARENT_CLASS)

#define ZCRX_NO_CONS_DEFINE_MEMBERS_WITH_PROPERTIES_WORKER(AUTOINIT, CLASS_NAME,PARENT_CLASS,PARENT_CLASS_STR, MAKEPROPS) \
	ZCRX_DEFINE_MEMBERS(CLASS_NAME); \
	void CLASS_NAME::rxInit() { \
	ZCRX_STATIC_CHECK(CLASS_NAME); \
	gpDesc = newZcRxClass(ZCRX_T(#CLASS_NAME), ZCRX_T(PARENT_CLASS_STR), \
	0, 0, 0, \
	0, 0, 0, 0, MAKEPROPS); \
}
#define ZCRX_NO_CONS_DEFINE_MEMBERS_WITH_PROPERTIES(CLASS_NAME,PARENT_CLASS, MAKEPROPS) \
	ZCRX_NO_CONS_DEFINE_MEMBERS_WITH_PROPERTIES_WORKER(ZCRX_AUTO_INIT_DEFAULT, CLASS_NAME,PARENT_CLASS,#PARENT_CLASS, MAKEPROPS)

#define ZCRX_NO_CONS_DEFINE_MEMBERS_WITH_PROPERTIES_AUTO(CLASS_NAME,PARENT_CLASS, MAKEPROPS) \
	ZCRX_NO_CONS_DEFINE_MEMBERS_WITH_PROPERTIES_WORKER(ZCRX_AUTO_INIT_QUEUE_EXPR, CLASS_NAME,PARENT_CLASS,#PARENT_CLASS, MAKEPROPS)

#define ZCRX_CONS_DEFINE_MEMBERS_WORKER(AUTOINIT, CLASS_NAME,PARENT_CLASS,PARENT_CLASS_STR,VERNO) \
	ZCRX_DEFINE_MEMBERS_WORKER(CLASS_NAME, AUTOINIT); \
	void CLASS_NAME::rxInit() { \
	ZCRX_STATIC_CHECK(CLASS_NAME); \
	gpDesc = newZcRxClass(ZCRX_T(#CLASS_NAME), ZCRX_T(PARENT_CLASS_STR), \
	VERNO, &zcrxInstantiateClass<CLASS_NAME>); \
}
#define ZCRX_CONS_DEFINE_MEMBERS(CLASS_NAME,PARENT_CLASS,VERNO) \
	ZCRX_CONS_DEFINE_MEMBERS_WORKER(ZCRX_AUTO_INIT_DEFAULT, CLASS_NAME, PARENT_CLASS, #PARENT_CLASS, VERNO)

#define ZCRX_CONS_DEFINE_MEMBERS_AUTO(CLASS_NAME,PARENT_CLASS,VERNO) \
	ZCRX_CONS_DEFINE_MEMBERS_WORKER(ZCRX_AUTO_INIT_QUEUE_EXPR, CLASS_NAME, PARENT_CLASS, #PARENT_CLASS, VERNO)

#define ZCRX_DXF_DEFINE_MEMBERS(CLASS_NAME,PARENT_CLASS,DWG_VERSION,\
	MAINTENANCE_VERSION,PROXY_FLAGS,DXF_NAME,APP) \
	ZCRX_DEFINE_MEMBERS(CLASS_NAME); \
	void CLASS_NAME::rxInit() { \
	ZCRX_STATIC_CHECK(CLASS_NAME); \
	gpDesc = newZcRxClass(ZCRX_T(#CLASS_NAME), ZCRX_T(#PARENT_CLASS), \
	DWG_VERSION,MAINTENANCE_VERSION,PROXY_FLAGS, \
	&zcrxInstantiateClass<CLASS_NAME>, ZCRX_T(#DXF_NAME), ZCRX_T(#APP)); \
} \
	void CLASS_NAME::rxInit(AppNameChangeFuncPtr ptr) { \
	ZCRX_STATIC_CHECK(CLASS_NAME); \
	gpDesc = newZcRxClass(ZCRX_T(#CLASS_NAME), ZCRX_T(#PARENT_CLASS), \
	DWG_VERSION,MAINTENANCE_VERSION,PROXY_FLAGS, \
	&zcrxInstantiateClass<CLASS_NAME>, ZCRX_T(#DXF_NAME), ZCRX_T(#APP), ptr); \
}

#define ZCRX_DXF_DEFINE_MEMBERS_WITH_PROPERTIES(CLASS_NAME,PARENT_CLASS,DWG_VERSION,\
	MAINTENANCE_VERSION,PROXY_FLAGS,DXF_NAME,APP, MAKEPROPS) \
	ZCRX_DEFINE_MEMBERS(CLASS_NAME); \
	void CLASS_NAME::rxInit() { \
	ZCRX_STATIC_CHECK(CLASS_NAME); \
	gpDesc = newZcRxClass(ZCRX_T(#CLASS_NAME), ZCRX_T(#PARENT_CLASS), \
	DWG_VERSION,MAINTENANCE_VERSION,PROXY_FLAGS, \
	&zcrxInstantiateClass<CLASS_NAME>, ZCRX_T(#DXF_NAME), ZCRX_T(#APP), NULL, MAKEPROPS); \
} \
	void CLASS_NAME::rxInit(AppNameChangeFuncPtr ptr) { \
	ZCRX_STATIC_CHECK(CLASS_NAME); \
	gpDesc = newZcRxClass(ZCRX_T(#CLASS_NAME), ZCRX_T(#PARENT_CLASS), \
	DWG_VERSION,MAINTENANCE_VERSION,PROXY_FLAGS, \
	&zcrxInstantiateClass<CLASS_NAME>, ZCRX_T(#DXF_NAME), ZCRX_T(#APP), ptr, MAKEPROPS); \
}

#pragma pack (pop)
#endif