#pragma once

#include "zrxobject.h"
#include "zGISManager.h"
#include "zJsonValue.h"

class ZWGIS_API ZcadGISFeatureServerReactor : public ZcRxObject
{
public:
	ZCRX_DECLARE_MEMBERS(ZcadGISFeatureServerReactor);

	ZcadGISFeatureServerReactor();
	virtual ~ZcadGISFeatureServerReactor();

	//messages:
public:
	virtual void beginAddFeatureServer(const ZcString& sServerUrl);
	virtual void abortAddFeatureServer(const ZcString& sServerUrl);
	virtual void addFeatureServerComplete(const ZcString& sServerUrl);

	virtual void beginAddFeatureLayer(const ZcString& sLayerName);
	virtual void abortAddFeatureLayer(const ZcString& sLayerName);
	virtual void addFeatureLayerComplete(const ZcString& sLayerName);

	virtual void beginGetFeatures(const ZcadJsonValue::ZcadJsonValueArray& featureIdArray);
	virtual void completeFeaturesChanged(double dPercent);
	virtual void abortGetFeatures();
	virtual void endGetFeatures();
};

