

#ifndef   _ZIDVER_H
#define   _ZIDVER_H

#include "zid.h"

#ifndef ZC_BLDENV
    #define ZCADV_BLDMAJOR  0
    #define ZCADV_BLDMINOR  0
    #define ZCADV_BLDBRANCH 0
    #define ZCADV_BLDSTREAM O
#else
    #include "_zidver.h"
#endif

#define VALUE2STR(x) #x
#define ID2STR(a) ID2STR__1(a)
#define ID2STR__1(a) VALUE2STR(a)

#define ZCADV_RCFILEVER1 ZCADV_RELMAJOR
#define ZCADV_RCFILEVER2 ZCADV_RELMINOR
#define ZCADV_RCFILEVER3 ZCADV_BLDMAJOR
#define ZCADV_RCFILEVER4 ZCADV_BLDMINOR
#define ZCADV_RCFILEVER5 ZCADV_BLDBRANCH

#define ZCADV_RCFILEVER1_CORRECTION (6 + ZCADV_RCFILEVER1)

#define ZCADV_RCFILEVERSTR ID2STR(ZCADV_RCFILEVER1) "." \
                ID2STR(ZCADV_RCFILEVER2) "." \
                ID2STR(ZCADV_RCFILEVER3) "." \
                ID2STR(ZCADV_RCFILEVER5) "." \
                ID2STR(ZCADV_RCFILEVER4)

#define ZCADV_PRODVERSION "R" ZCADV_RCFILEVERSTR

#if defined(_MSC_VER) || defined(UNICODE)

#define ZCADV_VERNUM  ZCRX_T(ID2STR(ZCADV_BLDSTREAM)) ZCRX_T(".") \
                      ZCRX_T(ID2STR(ZCADV_BLDMAJOR)) ZCRX_T(".") \
                      ZCRX_T(ID2STR(ZCADV_BLDBRANCH)) ZCRX_T(".") \
                      ZCRX_T(ID2STR(ZCADV_BLDMINOR))
#else 

#define ZCADV_VERNUM ID2STR(ZCADV_BLDSTREAM) "." \
                     ID2STR(ZCADV_BLDMAJOR) "." \
                     ID2STR(ZCADV_BLDBRANCH) "." \
                     ID2STR(ZCADV_BLDMINOR)
#endif 

#if defined(_MSC_VER) || defined(UNICODE)

#define ZCADV_VERNAME ZCRX_T(ID2STR(ZCADV_RELMAJOR)) ZCRX_T(".") \
                      ZCRX_T(ID2STR(ZCADV_RELMINOR))
#else 

#define ZCADV_VERNAME ID2STR(ZCADV_RELMAJOR) "." \
                      ID2STR(ZCADV_RELMINOR)
#endif 

#if defined(PRODUCTION)
#define ZCADV_VERFULL     ZCADV_VERNAME
#else
#define ZCADV_VERFULL     ZCADV_VERNUM
#endif

#define ZCADV_BLDVERSTR   ZCADV_VERNUM

#define ZCAD_COPYRIGHT    "Copyright (c)2019, ZWSOFT Inc. ("ZWCAD") "
#define ZCAD_COPYRIGHT_YEAR   "2019"

#define ZCAD_TLBVERSION_MAJOR   1
#define ZCAD_TLBVERSION_MINOR   0
#define ZCAD_TLBVERSION         ZCAD_TLBVERSION_MAJOR.ZCAD_TLBVERSION_MINOR

#ifdef _MSC_VER

#define ZCAD_TLBVERSIONSTR      ZCRX_T(ID2STR(ZCAD_TLBVERSION_MAJOR)) ZCRX_T(".") \
                                ZCRX_T(ID2STR(ZCAD_TLBVERSION_MINOR))
#else 

#define ZCAD_TLBVERSIONSTR      ID2STR(ZCAD_TLBVERSION_MAJOR) "." \
                                ID2STR(ZCAD_TLBVERSION_MINOR)
#endif

#define ZCDB_TLBVERSION_MAJOR   1
#define ZCDB_TLBVERSION_MINOR   0
#define ZCDB_TLBVERSION         ZCDB_TLBVERSION_MAJOR.ZCDB_TLBVERSION_MINOR

#ifdef _MSC_VER

#define ZCDB_TLBVERSIONSTR      ZCRX_T(ID2STR(ZCDB_TLBVERSION_MAJOR)) ZCRX_T(".") \
                                ZCRX_T(ID2STR(ZCDB_TLBVERSION_MINOR))
#else 

#define ZCDB_TLBVERSIONSTR      ID2STR(ZCDB_TLBVERSION_MAJOR) "." \
                                ID2STR(ZCDB_TLBVERSION_MINOR)
#endif

#endif
