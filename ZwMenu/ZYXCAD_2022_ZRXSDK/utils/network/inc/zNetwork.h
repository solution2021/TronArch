
#ifndef _Z_NETWORK_SDK_H_H_
#define _Z_NETWORK_SDK_H_H_

#include "zadesk.h"
#include "zAcString.h"

#ifdef ZWNETWORK_EXPORTS
#define ZWNETWORK_API __declspec(dllexport)
#else
#define ZWNETWORK_API
#endif

class ZcadJsonValue;
typedef enum 
{
	ZCNET_OK = 0,				
	ZCNET_INIT_FAILED,				//初始化CURL失败
	ZCNET_UNSUPPORTED_PROTOCOL,		//不支持的协议
	ZCNET_WRONG_URL,				//URL格式错误
	ZCNET_CONNECT_FAILED,			//连接失败
	ZCNET_CONNECT_TIMEOUT,			//连接超时
	ZCNET_WRONG_HTTPCODE,			//HTTP状态码为非成功状态
	ZCNET_PARSE_JSON_FAILED,		//解析JSON数据失败
	ZCNET_OTHER						//Other
} ZcNetCode;

class ZWNETWORK_API ZwNetwork
{
public:
	static bool send_get_raw(const ZcString& sUrl, std::string &rsRawResult, ZcNetCode& netCode);
	static bool send_get(const ZcString& sUrl, ZcadJsonValue& result, ZcNetCode& netCode);
	static bool send_post(const ZcString& sUrl, const ZcString& sPostfields, ZSoft::ULongPtr lPostfieldsLen, ZcadJsonValue& result, ZcNetCode& netCode);
	static bool downloadFile(const ZcString& sUrl, const ZcString& sDest, ZcNetCode& netCode);
	static bool readJsonFile(const ZcString& sFilePath, ZcadJsonValue& result);
};

#endif  //_Z_NETWORK_SDK_H_H_

