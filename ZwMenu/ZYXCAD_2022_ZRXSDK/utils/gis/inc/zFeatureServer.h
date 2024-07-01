
#ifndef _FEATURESERVER_H_H_
#define _FEATURESERVER_H_H_

struct ESRIDrawStyle
{
	double          m_dWidth;
	ZSoft::Int64    m_iColor[4];
	ZSoft::Int64    m_iOutlineColor[4];
	ZSoft::Int64    m_iSize;
	ZcString        m_sStyle;
	ZcString        m_sName;

	ESRIDrawStyle() : m_dWidth(1.0),
		m_iSize(0)
	{
		m_iColor[0] = 0;
		m_iColor[1] = 0;
		m_iColor[2] = 0;
		m_iColor[3] = 255;

		m_iOutlineColor[0] = 0;
		m_iOutlineColor[1] = 0;
		m_iOutlineColor[2] = 0;
		m_iOutlineColor[3] = 255;
	}
};

struct EsriFeatureRequestInfo
{
	ZSoft::Int64	m_iWKID;
	ZcDbExtents		m_BoundingBox;

	EsriFeatureRequestInfo() : m_iWKID(-1)
	{

	}
};

class ZWGIS_API ZcadFeatureServer
{
public:
	ZcadFeatureServer();
	virtual ~ZcadFeatureServer();

	bool addServer(const ZcString& sUrl, const EsriFeatureRequestInfo& krRequestInfo, ZcNetCode& rNetCode);
	
	const EsriFeatureRequestInfo& getRequestInfo();
	const WebFeatureLayerMap& getServerFeatureLayerInfoMap() const;

protected:
	bool getFeatureLayerInfo(const ZcString& sLayerUrl, const EsriFeatureRequestInfo& krRequestInfo, WebFeatureLayerInfo& webLayer, bool bIsSingleLayer = false);
	bool getFeaturesInfo(const ZcString& sLayerUrl, WebFeatureLayerInfo& webLayer);
	bool getPointInfo(const ZcadJsonValue::ZcadJsonValueArray& objArray, WebFeatureLayerInfo& webLayer);
	bool getLineInfo(const ZcadJsonValue::ZcadJsonValueArray& objArray, WebFeatureLayerInfo& webLayer);
	bool getPolygonInfo(const ZcadJsonValue::ZcadJsonValueArray& objArray, WebFeatureLayerInfo& webLayer);
	bool getMultiPointInfo(const ZcadJsonValue::ZcadJsonValueArray& objArray, WebFeatureLayerInfo& webLayer);
	bool getObjectAttributes(const ZcadJsonValue& objValue, const WebFeatureLayerInfo& webLayer, FeatureAttributeList& objAttributeList);
	bool getWKIDAndExtent(const ZcadJsonValue& objValue, const EsriFeatureRequestInfo& krRequestInfo, bool bIsSingleLayer = false);

	ZcDbObjectId appendFeatureToDb(ZcDbEntity* pEnt, ZcDbDatabase* pDb);

private:
	WebFeatureLayerMap                  m_FeatureLayerInfoMap;
	EsriFeatureRequestInfo				m_FeatureRequestInfo;
};

#endif  //_FEATURESERVER_H_H_
