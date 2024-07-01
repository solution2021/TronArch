
#ifndef _ZCAD_FEATURE_LAYER_HELPER_H_H_
#define _ZCAD_FEATURE_LAYER_HELPER_H_H_

#include <list>
#include <vector>
#include <map>
#include "zdbgroup.h"

#define ESRI_WEBFEATURELAYERS_DICT_NAME				ZW_T("ESRI_WEBFEATURELAYERS")
#define ESRI_FEATURES_DICT_NAME						ZW_T("ESRI_FEATURES")
#define ESRI_ATTRIBUTES_DICT_NAME					ZW_T("ESRI_ATTRIBUTES")

#define ESRI_FEATURELAYER_FEATURETYPE				ZW_T("FeatureType")
#define ESRI_FEATURELAYER_BLOCKNAME					ZW_T("BlockName")
#define ESRI_FEATURELAYER_CADLAYERNAME				ZW_T("CadLayerName")
#define ESRI_FEATURELAYER_CAPABILITIES				ZW_T("Capabilities")
#define ESRI_FEATURELAYER_CONNECTIONURL				ZW_T("ConnectionURL")
#define ESRI_FEATURELAYER_HASCURVES					ZW_T("HasCurves")
#define ESRI_FEATURELAYER_HASM						ZW_T("HasM")
#define ESRI_FEATURELAYER_HASZ						ZW_T("HasZ")
#define ESRI_FEATURELAYER_MODIFIEDIDS				ZW_T("ModifiedIDs")
#define ESRI_FEATURELAYER_OID						ZW_T("OID")
#define ESRI_FEATURELAYER_ORIGINALIDS				ZW_T("OriginalIDs")
#define ESRI_FEATURELAYER_PORTALITEMID				ZW_T("PortalItemId")
#define ESRI_FEATURELAYER_PORTALURL					ZW_T("PortalURL")
#define ESRI_FEATURELAYER_QUERYONLY					ZW_T("QueryOnly")
#define ESRI_FEATURELAYER_SERVICECAPABILITIES		ZW_T("ServiceCapabilities")
#define ESRI_FEATURELAYER_SERVICEFULLNAME			ZW_T("ServiceFullName")

#define ESRI_FEATURELAYER_FEATUREQUERY				ZW_T("FeatureQuery")

class ZWGIS_API FeatureAttribute
{
public:
	FeatureAttribute();
	FeatureAttribute(const FeatureAttribute& att);
	~FeatureAttribute();

	FeatureAttribute& operator = (const FeatureAttribute& att);
	bool operator < (FeatureAttribute& att);

public:
	ZcString				m_sName;
	resbuf*					m_pRbData;
	int						m_iIndex;
};

typedef std::list<FeatureAttribute> FeatureAttributeList;
struct DocFeatureQuery
{
	ZcString				m_sLayer;
	int						m_iColor;
	ZcString				m_sLineType;
	int						m_iLineWeight;

	DocFeatureQuery() :m_iColor(-1), m_iLineWeight(-4) {}
};

struct DocFeatureLayerInfo
{
	ZcString				m_sDocFeatureName;
	ZcString				m_sFeatureType;
	DocFeatureQuery			m_FeatureQuery;
	FeatureAttributeList	m_FeatureAttributeList;
};

struct WebFeatureLayerInfo
{
	bool					m_bQueryOnly;
	bool					m_bHasCurves;
	bool					m_bHasM;
	bool					m_bHasZ;
	int						m_iCapabilities;
	int						m_iServiceCapabilities;
	ZSoft::Int64			m_iLayerId;
	ZcString				m_sFeatureLayerName;
	ZcString				m_sConnectionURL;
	ZcString				m_sFeatureType;
	ZcString				m_sOID;
	ZcString				m_sPortalItemId;
	ZcString				m_sPortalURL;
	ZcString				m_sServiceFullName;
	ZcDbObjectId			m_FeatureLayerId;
	ZcDbObjectIdArray		m_ModifiedIDs;
	ZcDbObjectIdArray		m_OriginalIDs;
	FeatureAttributeList	m_FeatureAttributeList;

	WebFeatureLayerInfo() : m_bQueryOnly(true), m_bHasCurves(true), m_bHasM(false), m_bHasZ(false),
		m_iCapabilities(0), m_iServiceCapabilities(0), m_iLayerId(0) {}
};

typedef ZcArray<FeatureAttribute> FeatureAttributeArray;
typedef std::vector<FeatureAttributeList> AllObjectsAttributeVector;
typedef std::map<ZcString, DocFeatureLayerInfo> DocFeatureLayerMap;
typedef std::map<ZcString, WebFeatureLayerInfo> WebFeatureLayerMap;
class ZWGIS_API ZcadFeatureLayerHelper
{
public:
	static bool readAllFeatureLayers(DocFeatureLayerMap& docFeatureLayerMap, WebFeatureLayerMap& webFeatureLayerMap, const ZcDbDatabase* pDb = NULL, bool bOnlyAttributes = false);
	static bool readDocFeatureLayers(DocFeatureLayerMap& docFeatureLayerMap, const ZcDbDatabase* pDb = NULL, bool bOnlyAttributes = false);
	static bool readWebFeatureLayers(WebFeatureLayerMap& webFeatureLayerMap, const ZcDbDatabase* pDb = NULL, bool bOnlyAttributes = false);
	static bool readDocFeatureLayerInfo(const ZcDbDictionary* pFeatureLayerDict, DocFeatureLayerInfo& info, bool bOnlyAttributes = false);
	static bool readWebFeatureLayerInfo(const ZcDbDictionary* pFeatureLayerDict, WebFeatureLayerInfo& info, bool bOnlyAttributes = false);
	static bool readFeatureLayerAttributes(const ZcDbDictionary* pAttributesDict, FeatureAttributeList& attlist);
	static bool readFeatureObjectAttributes(const ZcDbDictionary* pAttributesDict, const FeatureAttributeList& featureAttList, FeatureAttributeArray& featureObjAttArray);
	static bool readDocFeatureLayerQuery(const ZcDbDictionary* pFeatureLayerDict, DocFeatureQuery& featuewQuery);

	static bool readBooleanValue(const ZcDbDictionary* pFeatureLayerDict, const ZTCHAR* pName, bool& bVal);
	static bool readIntegerValue(const ZcDbDictionary* pFeatureLayerDict, const ZTCHAR* pName, int& iVal);
	static bool readStringValue(const ZcDbDictionary* pFeatureLayerDict, const ZTCHAR* pName, ZcString& sVal);
	static bool readIdValue(const ZcDbDictionary* pFeatureLayerDict, const ZTCHAR* pName, ZcDbObjectId& idVal, ZcDbDatabase* pDb = NULL);
	static bool readIdsValue(const ZcDbDictionary* pFeatureLayerDict, const ZTCHAR* pName, ZcDbObjectIdArray& idsVal, ZcDbDatabase* pDb = NULL);

	static bool writeAllFeatureLayer(const DocFeatureLayerMap& docFeatureLayerMap, const WebFeatureLayerMap& webFeatureLayerMap, const ZcDbDatabase* pDb = NULL, bool bOnlyAttributes = false);
	static bool writeDocFeatureLayer(const DocFeatureLayerMap& docFeatureLayerMap, const ZcDbDatabase* pDb = NULL, bool bOnlyAttributes = false);
	static bool writeWebFeatureLayer(const WebFeatureLayerMap& webFeatureLayerMap, const ZcDbDatabase* pDb = NULL, bool bOnlyAttributes = false);
	static bool writeDocFeatureLayerInfo(ZcDbDictionary* pFeatureLayerDict, const DocFeatureLayerInfo& info, bool bOnlyAttributes = false);
	static bool writeWebFeatureLayerInfo(ZcDbDictionary* pFeatureLayerDict, const WebFeatureLayerInfo& info, bool bOnlyAttributes = false);
	static bool writeFeatureLayerAttributes(ZcDbDictionary* pFeatureLayerDict, const FeatureAttributeList& attlist);
	static bool writeFeatureObjectAttributes(const ZcDbObjectId& Id, const FeatureAttributeList& objAttributeList);
	static bool writeAttributeValue(ZcDbDictionary* pAttDict, const ZTCHAR* pAttName, const resbuf* pRb);

	static bool writeDocFeatureLayerQuery(ZcDbDictionary* pAttDict, const DocFeatureQuery& featuewQuery);
	static bool writeBooleanValue(ZcDbDictionary* pFeatureLayerDict, const ZTCHAR* pName, const bool bVal);
	static bool writeIntegerValue(ZcDbDictionary* pFeatureLayerDict, const ZTCHAR* pName, const int iVal);
	static bool writeStringValue(ZcDbDictionary* pFeatureLayerDict, const ZTCHAR* pName, const ZcString& sVal);
	static bool writeIdValue(ZcDbDictionary* pFeatureLayerDict, const ZTCHAR* pName, const ZcDbObjectId& idVal);
	static bool writeIdsValue(ZcDbDictionary* pFeatureLayerDict, const ZTCHAR* pName, const ZcDbObjectIdArray& idsVal);
	static bool writeOriginalIdsValue(ZcDbDictionary* pFeatureLayerDict, const ZTCHAR* pName, const ZcDbObjectIdArray& idsVal);
	static bool writeEmptyValue(ZcDbDictionary* pDict, const ZTCHAR* pName);
};


#endif  //_ZCAD_FEATURE_LAYER_HELPER_H_H_

