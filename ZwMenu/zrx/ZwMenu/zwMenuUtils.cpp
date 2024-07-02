#include "stdafx.h"
#include "acprofile.h"
extern CString g_strInstallPath;

#ifdef _ZCAD
	CString subkey = _T("Software\\ZWSOFT\\ZWCAD");
	CString srcPath = _T("ZWCADSEARCHPATH");
#elif _ZYXCAD
	CString subkey = _T("Software\\ZYXTECHNOLOGY\\ZYXCAD");
	CString srcPath = _T("SEARCHPATH");
#endif

void RegAppendWorkingFolder()
{
	Acad::ErrorStatus es;
	CZdUiRegistryAccess regapp;

	CString fullkey, profileName;
	//CString subkey = _T("Software\\ZWSOFT\\ZWCAD");
	if(regapp.Open(HKEY_CURRENT_USER, subkey))
	{
		CString version = regapp.GetString(_T("CurVer"));
		fullkey.Format(_T("%s\\%s"),subkey,version);
		regapp.Close();
	}

	if(regapp.Open(HKEY_CURRENT_USER, fullkey))
	{
		CString lang = regapp.GetString(_T("CurVer"));
		subkey.Format(_T("%s\\%s\\Profiles"),fullkey,lang);
		regapp.Close();
	}

	if(regapp.Open(HKEY_CURRENT_USER, subkey))
	{
		profileName = regapp.GetString(_T(""));
		fullkey.Format(_T("%s\\%s\\Config"),subkey,profileName);
		regapp.Close();
	}

	if(regapp.Open(HKEY_CURRENT_USER, fullkey))
	{
		CString spath = regapp.GetString(srcPath);
		//CString spath = regapp.GetString(_T("ZWCADSEARCHPATH"));

		regapp.Close();

		int curPos = 0;
		bool isExist = false;
		CString resToken= spath.Tokenize(_T(";"),curPos);
		while (resToken != _T(""))
		{
		   if(-1 != g_strInstallPath.Find(resToken))
		   {
			   isExist = true;
			   break;
		   }
		   resToken = spath.Tokenize(_T(";"), curPos);
		}; 

		if(isExist == false)
		{
			CString strTemp;
			CString newPath = spath;
			strTemp.Format(_T("%sHELP;"), g_strInstallPath);
			newPath += strTemp;
			strTemp.Format(_T("%sMENU;"), g_strInstallPath);
			newPath += strTemp;
			strTemp.Format(_T("%sPRG\\DCL;"), g_strInstallPath);
			newPath += strTemp;
			strTemp.Format(_T("%sPRG\\LISP;"), g_strInstallPath);
			newPath += strTemp;
			strTemp.Format(_T("%sPRG\\SLD;"), g_strInstallPath);
			newPath += strTemp;
			strTemp.Format(_T("%sSHEET;"), g_strInstallPath);
			newPath += strTemp;

			ads_setenv(_T("ACAD"), newPath.GetBuffer(0));

			CString path ; path.Format(_T("%sMenu\\install.txt"),g_strInstallPath);
			CStdioFile file;
			if(TRUE== file.Open(path, CFile::modeCreate | CFile::modeWrite | CFile::typeText))
			{
				file.WriteString(g_strInstallPath);
				file.Close();
			}
		}
	}

}