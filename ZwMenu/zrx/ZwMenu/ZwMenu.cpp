//Initialization functions
#include "StdAfx.h"
#include "resource.h"
#include <afxdllx.h>
#include "Registry.h"

extern void RegAppendWorkingFolder();

HINSTANCE _hdllInstance =NULL ;
CString g_strInstallPath;

// This command registers an ARX command.
void AddCommand(const TCHAR* cmdGroup, const TCHAR* cmdInt, const TCHAR* cmdLoc,
				const int cmdFlags, const AcRxFunctionPtr cmdProc, const int idLocal = -1);


// NOTE: DO NOT edit the following lines.
//{{AFX_ARX_MSG
void InitApplication();
void UnloadApplication();
void OnkLoadDwgMsg();
void OnkUnloadDwgMsg();
//}}AFX_ARX_MSG

// NOTE: DO NOT edit the following lines.
//{{AFX_ARX_ADDIN_FUNCS
//}}AFX_ARX_ADDIN_FUNCS

AC_IMPLEMENT_EXTENSION_MODULE(zwMenuDLL);


// Now you can use the CAcModuleResourceOverride class in
// your application to switch to the correct resource instance.
// Please see the ObjectARX Documentation for more details

/////////////////////////////////////////////////////////////////////////////
// DLL Entry Point
extern "C"
BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID /*lpReserved*/)
{
	if (dwReason == DLL_PROCESS_ATTACH)
	{
        _hdllInstance = hInstance;
		// Extension DLL one time initialization
		zwMenuDLL.AttachInstance(hInstance);
		InitAcUiDLL();
	} 
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		// Terminate the library before destructors are called
		zwMenuDLL.DetachInstance();
	}
	return TRUE;    // ok
}

/////////////////////////////////////////////////////////////////////////////
// ObjectARX EntryPoint
extern "C" AcRx::AppRetCode 
zcrxEntryPoint(AcRx::AppMsgCode msg, void* pkt)
{
	switch (msg) 
	{
	case AcRx::kUnloadDwgMsg:
		OnkUnloadDwgMsg();
		break;
	case AcRx::kLoadDwgMsg:
		OnkLoadDwgMsg();
		break;
	case AcRx::kInitAppMsg:
		// Comment out the following line if your
		// application should be locked into memory
		acrxDynamicLinker->unlockApplication(pkt);
		acrxDynamicLinker->registerAppMDIAware(pkt);

		InitApplication();

		break;
	case AcRx::kUnloadAppMsg:
		UnloadApplication();
		break;
	}
	return AcRx::kRetOK;
}

//==================================================================================

bool getMenuGroupFromName(IAcadMenuGroups* pMenuGroups, TCHAR* menuName, IAcadMenuGroup** zwMenuGroup)
{
	long nMenus =0;
	bool bFind = false;
	BSTR menuGroupName;

	pMenuGroups->get_Count(&nMenus);

	IAcadMenuGroup * pMenuGroup = NULL;
	BOOL found = FALSE;
	for(long i = 0 ; i < nMenus; i ++)
	{
		VARIANT vIndex;
		vIndex.vt = VT_I4;
		vIndex.lVal = i;

		HRESULT hr = pMenuGroups->Item(vIndex, &pMenuGroup);
		if(!FAILED(hr))
		{
			pMenuGroup->get_Name(&menuGroupName);
			CString sGroupName(menuGroupName);
			if(!_tcscmp(sGroupName , menuName))
			{
				bFind = true;
				*zwMenuGroup = pMenuGroup;
				break;
			}
			else
			{
				pMenuGroup->Release();
			}
		}
	}
	return bFind;
}

bool zwMenuLoad(TCHAR* myMenuName, TCHAR* menuPath)
{
	IAcadApplication* pAcadApp = NULL;
	IAcadMenuGroups* pMenuGroups = NULL;
	pAcadApp = (IAcadApplication*)acedGetAcadWinApp()->GetIDispatch(FALSE);
	HRESULT hr = pAcadApp->get_MenuGroups(&pMenuGroups);
	if(FAILED(hr))
	{
		return false;
	}
	
	//메뉴를 검색함
	long nMenus =0;
	bool bFind = false;
	BSTR menuGroupName;

	IAcadMenuGroup * pMenuGroup = NULL;
	if(getMenuGroupFromName(pMenuGroups, myMenuName, &pMenuGroup))
	{
		bFind = true;
		pMenuGroup->Release();
	}

	//해당메뉴가 없을때 메뉴를 로딩한다.
	if(bFind == false)
	{
		VARIANT menuName;
		VariantInit(&menuName);
		menuName.vt = VT_BSTR;
		menuName.bstrVal = CString(myMenuName).AllocSysString();

		CString menuNewPath(menuPath);
		IAcadMenuGroup* pNewMenuGroup = NULL;
		hr = pMenuGroups->Load(menuNewPath.AllocSysString(),menuName,&pNewMenuGroup);
		if(SUCCEEDED(hr))
		{
			bFind = true;
			pNewMenuGroup->Release();
		}
	}
	pMenuGroups->Release();
	return bFind;
}


// Init this application. Register your
// commands, reactors...
void InitApplication()
{
#ifdef _DEBUG
	CString msg;
#ifdef _Z2024
	msg.Format(_T("__zwMenu %s__ attach process ^^"),_T("2024"));
#elif _Z2022
	msg.Format(_T("__zwMenu %s__ attach process ^^"), _T("2022"));
#elif _Z2021
	msg.Format(_T("__zwMenu %s__ attach process ^^"), _T("2021"));
#elif _Z2020
	msg.Format(_T("__zwMenu %s__ attach process ^^"), _T("2020"));
#elif _Z2019
	msg.Format(_T("__zwMenu %s__ attach process ^^"),_T("2019"));
#elif _Z2018
	msg.Format(_T("__zwMenu %s__ attach process ^^"),_T("2018"));
#elif _Z2017
	msg.Format(_T("__zwMenu %s__ attach process ^^"),_T("2017"));
#endif
	AfxMessageBox(msg);
#endif
	
	try {

		InitCommonControls();

		// NOTE: DO NOT edit the following lines.
		//{{AFX_ARX_INIT
#ifdef _DEBUG
		//AddCommand(_T("IDWGCLIPBOARD"), _T("IDCB_TEST"), _T("CB_TEST"), ACRX_CMD_TRANSPARENT | ACRX_CMD_USEPICKSET, Test);
#endif
		//}}AFX_ARX_INIT

		TCHAR filename[_MAX_PATH];
		TCHAR dir[_MAX_DRIVE],path[_MAX_PATH];
		TCHAR fn[_MAX_FNAME],strMenu[_MAX_PATH];

		GetModuleFileName((HMODULE)_hdllInstance,filename,_MAX_PATH);
		_tsplitpath(filename,dir,path,fn,NULL);
		_stprintf(strMenu,_T("%s%s%s"),dir,path,_T("menu.txt"));
		//PREFIX_PRG <== dir,path
		g_strInstallPath.Format(_T("%s%s"),dir,path);

		//검색경로에 폴더를 추가
		//RegAppendWorkingFolder();
		CString path1 ; path1.Format(_T("%sMenu\\install.txt"),g_strInstallPath);
		CStdioFile file;
		if(TRUE== file.Open(path1, CFile::modeCreate | CFile::modeWrite | CFile::typeText))
		{
			file.WriteString(g_strInstallPath);
			file.Close();
		}



		CStdioFile iofile;
		if(iofile.Open(strMenu, CFile::modeRead | CFile::typeText))
		{
			CString menufile;
			while(iofile.ReadString(menufile))
			{
				menufile.Trim();
				if(menufile[0] == ';') continue;

				int pos = menufile.Find(_T(","));
				if(pos == -1) continue;

				CString menuName = menufile.Left(pos);
				CString menuPath = menufile.Mid(pos+1, menufile.GetLength());

				TCHAR rMenufile[_MAX_PATH];
				if(RTNORM == ads_findfile(menuPath, rMenufile))
				{
					zwMenuLoad(menuName.GetBuffer(),rMenufile);
				}
				else
				{
					//강제적으로 menu.txt파일을 로딩시킴
					CString findPath;
					findPath.Format(_T("%sMenu\\%s"),g_strInstallPath,menuPath);
					menuPath = findPath.GetBuffer(0);
					zwMenuLoad(menuName.GetBuffer(),menuPath.GetBuffer());
				}
			}
		}

	}
	catch (...)
	{
		ads_printf(_T("\nException in InitApplication."));
	}
}


// Unload this application. Unregister all objects
// registered in InitApplication.
void UnloadApplication()
{
	// NOTE: DO NOT edit the following lines.
	//{{AFX_ARX_EXIT
	acedRegCmds->removeGroup(_T("IDWGCLIPBOARD"));
	//}}AFX_ARX_EXIT
}

// This functions registers an ARX command.
// It can be used to read the localized command name
// from a string table stored in the resources.
void AddCommand(const TCHAR* cmdGroup, const TCHAR* cmdInt, const TCHAR* cmdLoc,
				const int cmdFlags, const AcRxFunctionPtr cmdProc, const int idLocal)
{
	TCHAR cmdLocRes[65];

	// If idLocal is not -1, it's treated as an ID for
	// a string stored in the resources.
	if (idLocal != -1) 
	{

		// Load strings from the string table and register the command.
		::LoadString(_hdllInstance, idLocal, cmdLocRes, 64);
		acedRegCmds->addCommand(cmdGroup, cmdInt, cmdLocRes, cmdFlags, cmdProc);

	} 
	else
	{
		// idLocal is -1, so the 'hard coded'
		// localized function name is used.
		acedRegCmds->addCommand(cmdGroup, cmdInt, cmdLoc, cmdFlags, cmdProc);
	}
}

//-----------------------------------------------------------------------------
// Entry point message handler function
void OnkLoadDwgMsg()
{
#ifdef OARXWIZDEBUG
	ads_printf ("\nOARXWIZDEBUG - OnkLoadDwgMsg() called.");
#endif // OARXWIZDEBUG
	TCHAR* str = (TCHAR*)acad_malloc(g_strInstallPath.GetLength() * 2);
	_tcscpy(str, g_strInstallPath.GetBuffer());

	resbuf* rb = ads_newrb(RTSTR);
	if(rb)
	{ 
		rb->restype = RTSTR;
		rb->resval.rstring = str;
		int ret = zds_putsym(_T("PREFIX_PRG"), rb);
		if(ret == RTNORM)
		{
			acad_free(str);
		}
		//ads_relrb(rb);
	}
}

//-----------------------------------------------------------------------------
// Entry point message handler function
void OnkUnloadDwgMsg()
{
#ifdef OARXWIZDEBUG
	ads_printf ("\nOARXWIZDEBUG - OnkUnloadDwgMsg() called.");
#endif // OARXWIZDEBUG
}