
#ifndef _ZCAD_MAPLAYER_HELPER_H_H_
#define _ZCAD_MAPLAYER_HELPER_H_H_

class ZcadMapAndImageLayerInfo;
typedef ZcArray<ZcadMapAndImageLayerInfo*> ZcadMapAndImageLayerInfoArray;
class ZWGIS_API ZcadMapAndImageLayerInfo
{
public:
	ZcadMapAndImageLayerInfo();
	ZcadMapAndImageLayerInfo(const ZcadMapAndImageLayerInfo& layer);
	virtual ~ZcadMapAndImageLayerInfo();

	ZcadMapAndImageLayerInfo& operator = (const ZcadMapAndImageLayerInfo& mapLayer);

	bool visible() const;
	void setVisible(bool bVisible);

	ZcString name() const;
	void setName(const ZcString& sName);

	ZSoft::Int64 layerId() const;
	void setLayerId(ZSoft::Int64 iLayerId);

	const ZcadMapAndImageLayerInfoArray& subLayers() const;
	void addSubLayer(ZcadMapAndImageLayerInfo* pSubLayer);
	void appendSubLayer(ZcadMapAndImageLayerInfoArray& subLayers);
	void clearSubLayers();

private:
	bool								m_bVisible;
	ZSoft::Int64						m_iLayerId;
	ZcString							m_sName;
	ZcadMapAndImageLayerInfoArray		m_SubLayers;
};

class ZWGIS_API ZcadMapAndImageLayer
{
public:
	ZcadMapAndImageLayer();
	ZcadMapAndImageLayer(const ZcadMapAndImageLayer& mapLayer);
	virtual ~ZcadMapAndImageLayer();

	ZcadMapAndImageLayer& operator = (const ZcadMapAndImageLayer& mapLayer);

	bool dynamic() const;
	void setDynamic(bool bVal);

	bool visible() const;
	void setVisible(bool bVisible);

	ZSoft::Int64 layerId() const;
	void setLayerId(ZSoft::Int64 iLayerId);

	ZSoft::Int64 transparency() const;
	void setTransparency(ZSoft::Int64 iTrans);

	ZSoft::Int64 version() const;
	void setVersion(ZSoft::Int64 iVersion);

	ZSoft::Int64 layerTypeValue() const;
	void setLayerTypeValue(ZSoft::Int64 iVal);

	ZcString layerTypeDisplayName() const;
	void setLayerTypeDisplayName(const ZcString& sName);

	ZcString name() const;
	void setName(const ZcString& sName);

	ZcString portalItemId() const;
	void setPortalItemId(const ZcString& sId);

	ZcString portalUri() const;
	void setPortalUri(const ZcString& sUri);

	ZcString sourceUri() const;
	void setSourceUri(const ZcString& sUri);

	ZSoft::Int64 wkid() const;
	void setWkid(ZSoft::Int64 iWkid);

	const ZcadMapAndImageLayerInfoArray& layers() const;
	void addLayer(ZcadMapAndImageLayerInfo* pSubLayer);
	void appendLayer(ZcadMapAndImageLayerInfoArray& layers);
	void clearLayers();

private:
	bool								m_bDynamic;
	bool								m_bVisible;
	ZSoft::Int64						m_iLayerId;
	ZSoft::Int64						m_iTransparency;
	ZSoft::Int64						m_iVersion;
	ZSoft::Int64						m_iLayerTypeValue;
	ZSoft::Int64						m_iWkid;
	ZcString							m_sLayerTypeDisplayName;
	ZcString							m_sName;
	ZcString							m_sPortalItemId;
	ZcString							m_sPortalUri;
	ZcString							m_sSourceUri;
	ZcadMapAndImageLayerInfoArray		m_Layers;
};

typedef std::map<ZcString, ZcadMapAndImageLayer> ZcadMapAndImageLayerMap;
class ZWGIS_API ZcadMapAndImageLayerHelper
{
public:
	static bool readAllMapLayers(ZcadMapAndImageLayerMap& layerMap, const ZcDbDatabase* pDb = NULL);
	static bool parseMapLayersString(const ZcString& sMapLayers, ZcadMapAndImageLayerMap& layerMap);
	static bool parseSubMapLayers(const ZcadJsonValue& mapInfoRoot, ZcadMapAndImageLayerInfoArray& layers);

	static bool writeAllMapLayers(ZcadMapAndImageLayerMap& layerMap, ZcDbDatabase* pDb = NULL);
	static bool convertSubMapLayersToString(const ZcadMapAndImageLayerInfoArray& layers, ZcString& sSubLayers);
};

#endif  //_ZCAD_MAPLAYER_HELPER_H_H_
