
#ifndef _ZC_JSON_VALUE_H_H_
#define _ZC_JSON_VALUE_H_H_

#include "zadesk.h"
#include <map>
#include <vector>
#include "zNetwork.h"
#include "zAcString.h"

class ZcadImpJsonValue;

class ZWNETWORK_API ZcadJsonValue
{
public:
	typedef std::vector<ZcadJsonValue> ZcadJsonValueArray;
	typedef std::map<ZcString, ZcadJsonValue> ZcadJsonValueMap;

	enum ValueType {
		eNullValue = 0, ///< 'null' value
		eIntValue,      ///< signed integer value
		eUIntValue,     ///< unsigned integer value
		eRealValue,     ///< double value
		eStringValue,   ///< UTF-8 string value
		eBooleanValue,  ///< bool value
		eArrayValue,    ///< array value (ordered list)
		eObjectValue    ///< object value (collection of name/value pairs).
	};

	ZcadJsonValue();
	ZcadJsonValue(ValueType type);
	ZcadJsonValue(const ZcadJsonValue& val);
	virtual ~ZcadJsonValue();

	static bool StringToZcadJsonValue(const ZcString& strVal, ZcadJsonValue& val);
	static bool ZcadJsonValueToString(const ZcadJsonValue& Value, ZcString& strVal);

	ValueType getValueType() const;

	bool getIntValue(ZSoft::Int64& iVal) const;
	bool getUIntValue(ZSoft::UInt64& uiVal) const;
	bool getRealValue(double& dVal) const;
	bool getStringValue(ZcString& strVal) const;
	bool getBooleanValue(ZSoft::Boolean& bVal) const;
	bool getArrayValue(ZcadJsonValueArray& arrayVal) const;
	bool getObjectValue(ZcadJsonValueMap& objectVal) const;

	bool getMemberIntValue(const ZcString& sKey, ZSoft::Int64& iVal) const;
	bool getMemberUIntValue(const ZcString& sKey, ZSoft::UInt64& uiVal) const;
	bool getMemberRealValue(const ZcString& sKey, double& dVal) const;
	bool getMemberStringValue(const ZcString& sKey, ZcString& strVal) const;
	bool getMemberBooleanValue(const ZcString& sKey, ZSoft::Boolean& bVal) const;
	bool getMemberArrayValue(const ZcString& sKey, ZcadJsonValueArray& arrayVal) const;
	bool getMemberObjectValue(const ZcString& sKey, ZcadJsonValueMap& objectVal) const;

	ZcadJsonValue& operator = (const ZcadJsonValue& val);

	ZcadImpJsonValue* getImpJsonValue() const;

private:
	ZcadImpJsonValue*		m_pImpJsonValue;
};

#endif  //_ZC_JSON_VALUE_H_H_

