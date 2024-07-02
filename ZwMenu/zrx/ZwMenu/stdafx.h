// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 및 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.

#pragma once

#pragma warning(disable: 4786)
#pragma warning(disable: 4996)
#pragma warning(disable: 4819)


#define STRICT
#ifndef _WIN32_WINNT
	#define _WIN32_WINNT 0x0600
#endif

// 'DEBUG workaround' below prevents the MFC or ATL #include-s 
// from pulling in "afx.h" that would force the debug CRT through
// #pragma-s.
#if defined(_DEBUG) && !defined(_FULLDEBUG_)
#define _DEBUG_WAS_DEFINED
#undef _DEBUG
#pragma message ("     Compiling MFC header files in release mode.")
#endif

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions

#ifndef _AFX_NO_OLE_SUPPORT
#include <afxole.h>         // MFC OLE classes
#include <afxodlgs.h>       // MFC OLE dialog classes
#include <afxdisp.h>        // MFC Automation classes
#endif // _AFX_NO_OLE_SUPPORT

#ifndef _AFX_NO_DB_SUPPORT
#include <afxdb.h>          // MFC ODBC database classes
#endif // _AFX_NO_DB_SUPPORT

#ifndef _AFX_NO_DAO_SUPPORT
#include <afxdao.h>         // MFC DAO database classes
#endif // _AFX_NO_DAO_SUPPORT

#include <afxdtctl.h>       // MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>         // MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#include "tchar.h"

//STL includes
#include <list>
#include <map>
#include <vector>
#include <deque>
#include <set>
#include <algorithm>

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#ifdef _DEBUG_WAS_DEFINED
#define _DEBUG
#undef _DEBUG_WAS_DEFINED
#endif

extern HINSTANCE _hdllInstance ;

// RX Includes
#include "acdb.h"               // acdb definitions
#include "rxregsvc.h"           // ARX linker
#include "aced.h"               // aced stuff
#include "adslib.h"             // RXADS definitions

// AutoCAD MFC Extensions:
#include "adui.h"
#include "acui.h"
#include "acuiComboBox.h"
#include "acuiDialog.h"


#include "dbapserv.h"           // Host application services
#include "acdocman.h"           // MDI document manager
#include "rxmfcapi.h"           // ObjectARX MFC support
#include "AcExtensionModule.h"  // Utility class for extension dlls

#ifdef _FULLDEBUG_
#pragma message ("Warning! You should better not run this application in a Standard AutoCAD release.")
#pragma message ("         Due to the memory managment constraints.")
#endif

// Include this here to speed up the compile times
#include "math.h"
#include "acadi.h"
