// ZwMenu2017.h : ZwMenu2017 DLL�� �⺻ ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CZwMenu2017App
// �� Ŭ������ ������ ������ ZwMenu2017.cpp�� �����Ͻʽÿ�.
//

class CZwMenu2017App : public CWinApp
{
public:
	CZwMenu2017App();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
