#ifndef __ACEDXREF_H__
#define __ACEDXREF_H__

#include "../inc/zacedxref.h"

#ifndef ACDB_PORT
#define ACDB_PORT		ZCDB_PORT
#endif //#ifndef ACDB_PORT

#ifndef AcDbBlockTableRecord
#define AcDbBlockTableRecord	ZcDbBlockTableRecord
#endif //#ifndef AcDbBlockTableRecord   

#ifndef acedXrefNotifyCheckFileChanged
#define acedXrefNotifyCheckFileChanged		zcedXrefNotifyCheckFileChanged
#endif //#ifndef acedXrefNotifyCheckFileChanged

#ifndef acedSkipXrefNotification
#define acedSkipXrefNotification		zcedSkipXrefNotification
#endif //#ifndef acedSkipXrefNotification

#ifndef acedSetXrefResolvedWithUpdateStatus
#define acedSetXrefResolvedWithUpdateStatus		zcedSetXrefResolvedWithUpdateStatus
#endif //#ifndef acedSetXrefResolvedWithUpdateStatus

#ifndef acedMarkForDelayXRefRelativePathResolve
#define acedMarkForDelayXRefRelativePathResolve		zcedMarkForDelayXRefRelativePathResolve
#endif //#ifndef acedMarkForDelayXRefRelativePathResolve

#ifndef acedUnmarkForDelayXRefRelativePathResolve
#define acedUnmarkForDelayXRefRelativePathResolve		zcedUnmarkForDelayXRefRelativePathResolve
#endif //#ifndef acedUnmarkForDelayXRefRelativePathResolve

#ifndef ACHAR
#define ACHAR		ZTCHAR
#endif //#ifndef ACHAR

#ifndef AcDbDatabase
#define AcDbDatabase		ZcDbDatabase
#endif //#ifndef AcDbDatabase

#ifndef AcDbObjectId
#define AcDbObjectId		ZcDbObjectId
#endif //#ifndef AcDbObjectId

#ifndef AcDbObjectIdArray
#define AcDbObjectIdArray		ZcDbObjectIdArray
#endif //#ifndef AcDbObjectIdArray

#ifndef AcGePoint3d
#define AcGePoint3d		ZcGePoint3d
#endif //#ifndef AcGePoint3d

#ifndef AcGeScale3d
#define AcGeScale3d		ZcGeScale3d
#endif //#ifndef AcGeScale3d

#ifndef Acad
#define Acad		Zcad
#endif //#ifndef Acad

#ifndef acedXrefAttach
#define acedXrefAttach		zcedXrefAttach
#endif //#ifndef acedXrefAttach

#ifndef acedXrefBind
#define acedXrefBind		zcedXrefBind
#endif //#ifndef acedXrefBind

#ifndef acedXrefCreateBlockname
#define acedXrefCreateBlockname		zcedXrefCreateBlockname
#endif //#ifndef acedXrefCreateBlockname

#ifndef acedXrefDetach
#define acedXrefDetach		zcedXrefDetach
#endif //#ifndef acedXrefDetach

#ifndef acedXrefOverlay
#define acedXrefOverlay		zcedXrefOverlay
#endif //#ifndef acedXrefOverlay

#ifndef acedXrefReload
#define acedXrefReload		zcedXrefReload
#endif //#ifndef acedXrefReload

#ifndef acedXrefResolve
#define acedXrefResolve		zcedXrefResolve
#endif //#ifndef acedXrefResolve

#ifndef acedXrefUnload
#define acedXrefUnload		zcedXrefUnload
#endif //#ifndef acedXrefUnload

#ifndef acedXrefXBind
#define acedXrefXBind		zcedXrefXBind
#endif //#ifndef acedXrefXBind

#endif //#ifndef __ACEDXREF_H__
