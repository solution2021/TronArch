
#ifndef _ZCAD_GIS_GLOBALS_H_H_
#define _ZCAD_GIS_GLOBALS_H_H_

#ifdef ZWGIS_EXPORTS
#define ZWGIS_API __declspec(dllexport)
#else
#define ZWGIS_API
#endif

struct ZcadCSInfo;
class ZcadJsonValue;
class ZcEdGISProcessReactor;

class ZWGIS_API ZcadGISManager
{
protected:
	ZcadGISManager();

public:
	virtual ~ZcadGISManager();

	static void initialize();
	static void unInitialize();

	bool getUniqueTempFileName(const ZcString& sFilePath, ZcString& sFileName);
	static bool loadCoordinateSystemJsonResource(int iResID, ZcadJsonValue& jsonValue);
	static bool isValidExtents(const ZcDbExtents& extents);
};

ZWGIS_API ZcadGISManager* ZcGetGISManager();

#endif  //_ZCAD_GIS_GLOBALS_H_H_



