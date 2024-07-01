
#ifndef _Z_GIS_COORDINATE_SYSTEM_H_H_
#define _Z_GIS_COORDINATE_SYSTEM_H_H_

#include "zadesk.h"
#include "zAcString.h"

enum ZcadCsType
{
	eUndefine = 0,
	eGeoGCS,
	ePrjJCS
};

struct ZcadCSInfo
{
	ZSoft::Int64		m_iWKID;
	ZcString			m_sWKT;
	ZcString			m_sName;
	ZcString			m_sDescription;
	ZcString			m_sUnits;
	ZcString			m_sArea;
	ZcString			m_sAreaName;
	ZcString			m_sCatMajor;
	ZcDbExtents		    m_extents;
};

typedef std::multimap<ZSoft::Int64, ZcadCSInfo> CoordinateSystemMap;
typedef std::multimap<ZcString, ZSoft::Int64> NameToWKIDMap;

class ZWGIS_API ZcadGISCoordinateSystem
{
public:
	static bool getWKIDFromName(const ZcString& sName, ZSoft::UInt64& iWKID);
	static bool getWKTFromWKID(ZSoft::UInt64 iWKID, ZcString& sWKText, ZcadCsType type = eUndefine);
	static bool getCoordinateSystemFromWKID(ZSoft::UInt64 iWKID, ZcadCSInfo& cs, ZcadCsType type = eUndefine);

	static bool getWKIDfromDefineInfo(const ZcString& sDefineInfo, ZSoft::UInt64& iWKID);
	static bool readPrjFile(const ZTCHAR* pFilePath, ZcadCSInfo& cs);

	static bool getPrjCoordinateSystemsMap(CoordinateSystemMap& rCSPrjMap);
	static bool getGeoCoordinateSystemsMap(CoordinateSystemMap& rCSGeoMap);
};

#endif  //_Z_GIS_COORDINATE_SYSTEM_H_H_


