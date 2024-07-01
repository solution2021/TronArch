#ifndef __ACDB_H__
#define __ACDB_H__

#include "adesk.h"
#include "AdAChar.h"

#include "../inc/zacdb.h"

#ifndef ACDB_SERVICES
#define ACDB_SERVICES		ZCDB_SERVICES
#endif //#ifndef ACDB_SERVICES

#ifndef ACDB_BROKEN_HANDLE
#define ACDB_BROKEN_HANDLE		ZCDB_BROKEN_HANDLE
#endif //#ifndef ACDB_BROKEN_HANDLE

#ifndef ACDB_DETAILSTYLE_DICTIONARY
#define ACDB_DETAILSTYLE_DICTIONARY		ZCDB_DETAILSTYLE_DICTIONARY
#endif //#ifndef ACDB_DETAILSTYLE_DICTIONARY

#ifndef ACDB_SECTIONSTYLE_DICTIONARY
#define ACDB_SECTIONSTYLE_DICTIONARY		ZCDB_SECTIONSTYLE_DICTIONARY
#endif //#ifndef ACDB_SECTIONSTYLE_DICTIONARY

#ifndef acdbAnnotationScaleCollectionName
#define acdbAnnotationScaleCollectionName		zcdbAnnotationScaleCollectionName
#endif //#ifndef acdbAnnotationScaleCollectionName

#ifndef ACAD_COLOR
#define ACAD_COLOR		ZCAD_COLOR
#endif //#ifndef ACAD_COLOR

#ifndef ACAD_DATALINK
#define ACAD_DATALINK		ZCAD_DATALINK
#endif //#ifndef ACAD_DATALINK

#ifndef ACAD_ENHANCEDBLOCK
#define ACAD_ENHANCEDBLOCK		ZCAD_ENHANCEDBLOCK
#endif //#ifndef ACAD_ENHANCEDBLOCK

#ifndef ACAD_ENHANCEDBLOCKEVALKEY
#define ACAD_ENHANCEDBLOCKEVALKEY		ZCAD_ENHANCEDBLOCKEVALKEY
#endif //#ifndef ACAD_ENHANCEDBLOCKEVALKEY

#ifndef ACAD_ENHANCEDBLOCK_REFERENCE
#define ACAD_ENHANCEDBLOCK_REFERENCE		ZCAD_ENHANCEDBLOCK_REFERENCE
#endif //#ifndef ACAD_ENHANCEDBLOCK_REFERENCE

#ifndef ACAD_FIELD
#define ACAD_FIELD		ZCAD_FIELD
#endif //#ifndef ACAD_FIELD

#ifndef ACAD_FIELDLIST
#define ACAD_FIELDLIST		ZCAD_FIELDLIST
#endif //#ifndef ACAD_FIELDLIST

#ifndef ACAD_GROUP
#define ACAD_GROUP		ZCAD_GROUP
#endif //#ifndef ACAD_GROUP

#ifndef ACAD_LAYERSTATES
#define ACAD_LAYERSTATES		ZCAD_LAYERSTATES
#endif //#ifndef ACAD_LAYERSTATES

#ifndef ACAD_LAYOUT
#define ACAD_LAYOUT		ZCAD_LAYOUT
#endif //#ifndef ACAD_LAYOUT

#ifndef ACAD_MATERIAL
#define ACAD_MATERIAL		ZCAD_MATERIAL
#endif //#ifndef ACAD_MATERIAL

#ifndef ACAD_MLEADERSTYLE
#define ACAD_MLEADERSTYLE		ZCAD_MLEADERSTYLE
#endif //#ifndef ACAD_MLEADERSTYLE

#ifndef ACAD_MLINESTYLE
#define ACAD_MLINESTYLE		ZCAD_MLINESTYLE
#endif //#ifndef ACAD_MLINESTYLE

#ifndef ACAD_OBJID_INLINE_INTERNAL
#define ACAD_OBJID_INLINE_INTERNAL		ZCAD_OBJID_INLINE_INTERNAL
#endif //#ifndef ACAD_OBJID_INLINE_INTERNAL

#ifndef ACAD_PLOTSETTINGS
#define ACAD_PLOTSETTINGS		ZCAD_PLOTSETTINGS
#endif //#ifndef ACAD_PLOTSETTINGS

#ifndef ACAD_PLOTSTYLENAME
#define ACAD_PLOTSTYLENAME		ZCAD_PLOTSTYLENAME
#endif //#ifndef ACAD_PLOTSTYLENAME

#ifndef ACAD_SECTION_MANAGER
#define ACAD_SECTION_MANAGER		ZCAD_SECTION_MANAGER
#endif //#ifndef ACAD_SECTION_MANAGER

#ifndef ACAD_TABLESTYLE
#define ACAD_TABLESTYLE		ZCAD_TABLESTYLE
#endif //#ifndef ACAD_TABLESTYLE

#ifndef ACAD_VISUALSTYLE
#define ACAD_VISUALSTYLE		ZCAD_VISUALSTYLE
#endif //#ifndef ACAD_VISUALSTYLE

#ifndef ACDB_ANNOTATIONSCALES
#define ACDB_ANNOTATIONSCALES		ZCDB_ANNOTATIONSCALES
#endif //#ifndef ACDB_ANNOTATIONSCALES

#ifndef ACDB_ASSOCNETWORK_DICTIONARY
#define ACDB_ASSOCNETWORK_DICTIONARY		ZCDB_ASSOCNETWORK_DICTIONARY
#endif //#ifndef ACDB_ASSOCNETWORK_DICTIONARY

#ifndef ACDB_CLOSE_BRACE_CHAR
#define ACDB_CLOSE_BRACE_CHAR		ZCDB_CLOSE_BRACE_CHAR
#endif //#ifndef ACDB_CLOSE_BRACE_CHAR

#ifndef ACDB_CLOSE_BRACE_STR
#define ACDB_CLOSE_BRACE_STR		ZCDB_CLOSE_BRACE_STR
#endif //#ifndef ACDB_CLOSE_BRACE_STR

#ifndef ACDB_COLOR_DICTIONARY
#define ACDB_COLOR_DICTIONARY		ZCDB_COLOR_DICTIONARY
#endif //#ifndef ACDB_COLOR_DICTIONARY

#ifndef ACDB_DATALINK
#define ACDB_DATALINK		ZCDB_DATALINK
#endif //#ifndef ACDB_DATALINK

#ifndef ACDB_EMBEDDED_OBJECT_STR
#define ACDB_EMBEDDED_OBJECT_STR		ZCDB_EMBEDDED_OBJECT_STR
#endif //#ifndef ACDB_EMBEDDED_OBJECT_STR

#ifndef ACDB_ENHANCED_BLOCK
#define ACDB_ENHANCED_BLOCK		ZCDB_ENHANCED_BLOCK
#endif //#ifndef ACDB_ENHANCED_BLOCK

#ifndef ACDB_ENHANCED_BLOCK_EVALKEY
#define ACDB_ENHANCED_BLOCK_EVALKEY		ZCDB_ENHANCED_BLOCK_EVALKEY
#endif //#ifndef ACDB_ENHANCED_BLOCK_EVALKEY

#ifndef ACDB_ENHANCED_BLOCK_REF
#define ACDB_ENHANCED_BLOCK_REF		ZCDB_ENHANCED_BLOCK_REF
#endif //#ifndef ACDB_ENHANCED_BLOCK_REF

#ifndef ACDB_FIELDLIST
#define ACDB_FIELDLIST		ZCDB_FIELDLIST
#endif //#ifndef ACDB_FIELDLIST

#ifndef ACDB_FIELD_DICTIONARY
#define ACDB_FIELD_DICTIONARY		ZCDB_FIELD_DICTIONARY
#endif //#ifndef ACDB_FIELD_DICTIONARY

#ifndef ACDB_GROUP_DICTIONARY
#define ACDB_GROUP_DICTIONARY		ZCDB_GROUP_DICTIONARY
#endif //#ifndef ACDB_GROUP_DICTIONARY

#ifndef ACDB_LAYERSTATES_DICTIONARY
#define ACDB_LAYERSTATES_DICTIONARY		ZCDB_LAYERSTATES_DICTIONARY
#endif //#ifndef ACDB_LAYERSTATES_DICTIONARY

#ifndef ACDB_LAYOUT_DICTIONARY
#define ACDB_LAYOUT_DICTIONARY		ZCDB_LAYOUT_DICTIONARY
#endif //#ifndef ACDB_LAYOUT_DICTIONARY

#ifndef ACDB_MATERIAL_DICTIONARY
#define ACDB_MATERIAL_DICTIONARY		ZCDB_MATERIAL_DICTIONARY
#endif //#ifndef ACDB_MATERIAL_DICTIONARY

#ifndef ACDB_MLEADERSTYLE_DICTIONARY
#define ACDB_MLEADERSTYLE_DICTIONARY		ZCDB_MLEADERSTYLE_DICTIONARY
#endif //#ifndef ACDB_MLEADERSTYLE_DICTIONARY

#ifndef ACDB_MLINESTYLE_DICTIONARY
#define ACDB_MLINESTYLE_DICTIONARY		ZCDB_MLINESTYLE_DICTIONARY
#endif //#ifndef ACDB_MLINESTYLE_DICTIONARY

#ifndef ACDB_MODEL_SPACE
#define ACDB_MODEL_SPACE		ZCDB_MODEL_SPACE
#endif //#ifndef ACDB_MODEL_SPACE

#ifndef ACDB_NULL_HANDLE
#define ACDB_NULL_HANDLE		ZCDB_NULL_HANDLE
#endif //#ifndef ACDB_NULL_HANDLE

#ifndef ACDB_OPEN_BRACE_CHAR
#define ACDB_OPEN_BRACE_CHAR		ZCDB_OPEN_BRACE_CHAR
#endif //#ifndef ACDB_OPEN_BRACE_CHAR

#ifndef ACDB_OPEN_BRACE_STR
#define ACDB_OPEN_BRACE_STR		ZCDB_OPEN_BRACE_STR
#endif //#ifndef ACDB_OPEN_BRACE_STR

#ifndef ACDB_PAPER_SPACE
#define ACDB_PAPER_SPACE		ZCDB_PAPER_SPACE
#endif //#ifndef ACDB_PAPER_SPACE

#ifndef ACDB_PLOTSETTINGS_DICTIONARY
#define ACDB_PLOTSETTINGS_DICTIONARY		ZCDB_PLOTSETTINGS_DICTIONARY
#endif //#ifndef ACDB_PLOTSETTINGS_DICTIONARY

#ifndef ACDB_PLOTSTYLENAME_DICTIONARY
#define ACDB_PLOTSTYLENAME_DICTIONARY		ZCDB_PLOTSTYLENAME_DICTIONARY
#endif //#ifndef ACDB_PLOTSTYLENAME_DICTIONARY

#ifndef ACDB_SECTION_MANAGER
#define ACDB_SECTION_MANAGER		ZCDB_SECTION_MANAGER
#endif //#ifndef ACDB_SECTION_MANAGER

#ifndef ACDB_TABLESTYLE_DICTIONARY
#define ACDB_TABLESTYLE_DICTIONARY		ZCDB_TABLESTYLE_DICTIONARY
#endif //#ifndef ACDB_TABLESTYLE_DICTIONARY

#ifndef ACDB_VISUALSTYLE_DICTIONARY
#define ACDB_VISUALSTYLE_DICTIONARY		ZCDB_VISUALSTYLE_DICTIONARY
#endif //#ifndef ACDB_VISUALSTYLE_DICTIONARY

#ifndef ACDB_ASSOCNETWORK_DICTIONARY
#define ACDB_ASSOCNETWORK_DICTIONARY		ZCDB_ASSOCNETWORK_DICTIONARY
#endif //#ifndef ACDB_ASSOCNETWORK_DICTIONARY

#ifndef ACRX_T
#define ACRX_T		ZCRX_T
#endif //#ifndef ACRX_T

#ifndef AD_COLOR
#define AD_COLOR		ZD_COLOR
#endif //#ifndef AD_COLOR

#ifndef AD_DATALINK
#define AD_DATALINK		ZD_DATALINK
#endif //#ifndef AD_DATALINK

#ifndef AD_ENHANCEDBLOCK
#define AD_ENHANCEDBLOCK		ZD_ENHANCEDBLOCK
#endif //#ifndef AD_ENHANCEDBLOCK

#ifndef AD_ENHANCEDBLOCKEVALKEY
#define AD_ENHANCEDBLOCKEVALKEY		ZD_ENHANCEDBLOCKEVALKEY
#endif //#ifndef AD_ENHANCEDBLOCKEVALKEY

#ifndef AD_ENHANCEDBLOCK_REFERENCE
#define AD_ENHANCEDBLOCK_REFERENCE		ZD_ENHANCEDBLOCK_REFERENCE
#endif //#ifndef AD_ENHANCEDBLOCK_REFERENCE

#ifndef AD_FIELD
#define AD_FIELD		ZD_FIELD
#endif //#ifndef AD_FIELD

#ifndef AD_FIELDLIST
#define AD_FIELDLIST		ZD_FIELDLIST
#endif //#ifndef AD_FIELDLIST

#ifndef AD_GROUP
#define AD_GROUP		ZD_GROUP
#endif //#ifndef AD_GROUP

#ifndef AD_LAYERSTATES
#define AD_LAYERSTATES		ZD_LAYERSTATES
#endif //#ifndef AD_LAYERSTATES

#ifndef AD_LAYOUT
#define AD_LAYOUT		ZD_LAYOUT
#endif //#ifndef AD_LAYOUT

#ifndef AD_MATERIAL
#define AD_MATERIAL		ZD_MATERIAL
#endif //#ifndef AD_MATERIAL

#ifndef AD_MLEADERSTYLE
#define AD_MLEADERSTYLE		ZD_MLEADERSTYLE
#endif //#ifndef AD_MLEADERSTYLE

#ifndef AD_MLINESTYLE
#define AD_MLINESTYLE		ZD_MLINESTYLE
#endif //#ifndef AD_MLINESTYLE

#ifndef AD_OBJID_INLINE_INTERNAL
#define AD_OBJID_INLINE_INTERNAL		ZD_OBJID_INLINE_INTERNAL
#endif //#ifndef AD_OBJID_INLINE_INTERNAL

#ifndef AD_PLOTSETTINGS
#define AD_PLOTSETTINGS		ZD_PLOTSETTINGS
#endif //#ifndef AD_PLOTSETTINGS

#ifndef AD_PLOTSTYLENAME
#define AD_PLOTSTYLENAME		ZD_PLOTSTYLENAME
#endif //#ifndef AD_PLOTSTYLENAME

#ifndef AD_SECTION_MANAGER
#define AD_SECTION_MANAGER		ZD_SECTION_MANAGER
#endif //#ifndef AD_SECTION_MANAGER

#ifndef AD_TABLESTYLE
#define AD_TABLESTYLE		ZD_TABLESTYLE
#endif //#ifndef AD_TABLESTYLE

#ifndef AD_VISUALSTYLE
#define AD_VISUALSTYLE		ZD_VISUALSTYLE
#endif //#ifndef AD_VISUALSTYLE

#ifndef AcDb
#define AcDb		ZcDb
#endif //#ifndef AcDb

#ifndef AcDbDwgVersion
#define AcDbDwgVersion		ZcDbDwgVersion
#endif //#ifndef AcDbDwgVersion

#ifndef AcDbServices
#define AcDbServices		ZcDbServices
#endif //#ifndef AcDbServices

#ifndef Adesk
#define Adesk		ZSoft
#endif //#ifndef Adesk

#ifndef ACDB_ANNOTATIONSCALES_COLLECTION
#define ACDB_ANNOTATIONSCALES_COLLECTION		ZCDB_ANNOTATIONSCALES_COLLECTION
#endif //#ifndef ACDB_ANNOTATIONSCALES_COLLECTION

#endif //#ifndef __ACDB_H__
