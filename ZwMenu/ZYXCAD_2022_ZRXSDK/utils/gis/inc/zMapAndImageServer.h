
#ifndef _ZCAD_MAP_SERVER_H_H_
#define _ZCAD_MAP_SERVER_H_H_

#include "zMapAndImageLayerHelper.h"

struct EsriMapRequestInfo
{
	ZSoft::Int64	m_iWKID;
	ZSoft::Int64	m_iLayerId;
	ZcDbExtents		m_BoundingBox;
	bool			m_bIsMapServer;

	EsriMapRequestInfo() : m_iWKID(-1)
		, m_bIsMapServer(true)
		, m_iLayerId(1)
	{

	}
};

class ZWGIS_API ZcadMapAndImageServer
{
public:
	ZcadMapAndImageServer();
	virtual ~ZcadMapAndImageServer();

	bool addServer(const ZcString& sUrl,const EsriMapRequestInfo& krMapRequestInfo, ZcNetCode& rNetCode);
	bool updateServer(const EsriMapRequestInfo& krMapRequestInfo, ZcNetCode& rNetCode);

	const EsriMapRequestInfo& getRequestInfo();

	void setCustomImageFilePath(const ZcString& sPath);
	const ZcString& getCustomImageFilePath() const;

	const ZcString& getImageTmpFilePathName() const;
	ZcadMapAndImageLayer& getMapAndImageLayer();

	const ZcDbExtents& getFullExtent() const;
private:
	ZcString					m_sImageTmpFilePathName;
	ZcString					m_sCustomImageFilePath;
	ZcadMapAndImageLayer		m_MapLayerInfo;
	EsriMapRequestInfo			m_MapRequestInfo;
	ZcDbExtents					m_FullExtent;

};

#endif  //_ZCAD_MAP_SERVER_H_H_

