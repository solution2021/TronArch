#ifndef  _ZCAD_COORDINATE_TRANSFORMATION_H_H_
#define  _ZCAD_COORDINATE_TRANSFORMATION_H_H_

#include "zGISManager.h"

class ZWGIS_API ZcadCoordinateTransformation
{
public:
	bool TransformEntity(ZcDbEntity* pEnt, ZSoft::UInt64 ioldWKID, ZSoft::UInt64 inewWKID);
	bool TransformPoint(ZSoft::UInt64 ioldWKID, ZSoft::UInt64 inewWKID, const ZcGePoint3d& oldPt, ZcGePoint3d& newPt);
	bool TransformPolyline(ZSoft::UInt64 ioldWKID, ZSoft::UInt64 inewWKID, ZcDbPolyline* pline);
	ZcString GetTransformURL(ZSoft::UInt64 ioldWKID, ZSoft::UInt64 inewWKID);
};

#endif //_ZCAD_COORDINATE_TRANSFORMATION_H_H_
